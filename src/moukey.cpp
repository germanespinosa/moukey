#include <moukey.h>
#include <iostream>
#include <cinttypes>
#include <sys/stat.h>
#include <util.h>
#include <mutex>

using namespace std;

namespace moukey{

// thread handlers
    void print_events(Device &d){
        d.listen();
        while (d.wait_for_event()) {
            cout << d.event << endl;
        }
    }
    mutex mtx2;
    void process_device_events(int16_t device_index, Device_pool &dp, Server &server, Event_data &modifier, Event_data &trigger){
        bool modifier_on = false;
        auto &device = dp[device_index];
        device.listen();
        mtx2.lock();
        LOG("listening " << device.name() << " on " << device_index);
        mtx2.unlock();
        while (device.wait_for_event()) {
            LOG ( "event "<< device.event << " for " << device << " " << device.name());
            if (modifier.type == device.event.data.type
                && modifier.code == device.event.data.code) {
                if (device.event.data.value < 2) {
                    modifier_on = device.event.data.value;
                    LOG(string("modifier: ") + (modifier_on?"on":"off"));
                }
            }
            if (modifier_on
                && trigger.type == device.event.data.type
                && trigger.code == device.event.data.code
                && device.event.data.value ) {
                LOG ("switching connection");
                server.next_connection();
            } else {
                if (server.dispatch_event(device_index, device.event)) {
                    LOG("event dispatch success");
                } else {
                    LOG("event dispatch fail");
                }
            }
        }
    }

    void receive_event(Client &client, Virtual_device &vd){
        LOG("waiting for events");
        while (client.wait_for_event()) {
            LOG(client.event);
            vd.dispatch(client.device_ind, client.event);
        }
        LOG("connection closed");
        exit(1);
    }
// end thread handlers

    void device_list(){
        Device_pool dp;
        dp.init();
        dp.list_devices();
    }

    void device_list(unsigned int device_ind){
        Device_pool dp;
        dp.init();
        if (device_ind< dp.devices.size()) {
            cout << dp[device_ind].name() << endl;
        }
        else {
            cerr << "Device not found" << endl;
            exit(1);
        }
    }

    void device_test(const vector<string> &device_names, int secs){
        Device_pool dp;
        if (!dp.init(device_names)) {
            cerr << "Failed to init devices" << endl;
            exit(1);
        }
        vector<thread> t;
        for (auto &d:dp.devices) t.emplace_back(print_events, ref(d));

        this_thread::sleep_for(chrono::milliseconds(secs * 1000) );
        dp[0].stop_listening();
        for (auto &s:t)
            s.join();
    }

    void device_display(const std::string &device_name){
        Device_pool dp;
        unsigned int size = 0;
        dp.init(device_name);
        if (dp.devices.empty()) {
            cerr << "Failed to init " << device_name << endl;
            exit(1);
        }
        cout << dp[size] << endl;
    }

    void device_display(const std::vector<std::string>& device_names){
        Device_pool dp;
        unsigned int size = 0;
        for (auto &device_name: device_names) {
            dp.init(device_name);
            if (dp.devices.size() == size) {
                cerr << "Failed to init " << device_name << endl;
                exit(1);
            }
            cout << dp[size] << endl;
            size ++;
        }
    }

    void device_server(int port, vector<string> device_names) {
        device_server(port, device_names,-1);
    }

    void device_server(int port, vector<string> device_names, int duration){
        Device_pool dp;
        if (device_names.empty()){
            dp.init();
        } else {
            dp.init(device_names);
        }
        Server server(dp.device_names);
        if (!server.start(port)) {
            cerr << "failed to start server" << endl;
        };
        vector<thread> threads;
        Event_data modifier{};
        modifier.type = 1;
        modifier.code = 125;
        Event_data trigger{};
        trigger.type = 1;
        trigger.code = 41;
        for (int i=0;i<dp.devices.size(); i++) {
            auto &device = dp.devices[i];
            LOG("creating thread for " << device.name());
            threads.emplace_back(process_device_events, i,  ref(dp), ref(server), ref(modifier), ref(trigger));
        }
        if (duration<=0) while(true);
        this_thread::sleep_for(chrono::milliseconds(duration*1000) );
        for (auto &device: dp.devices)
            device.stop_listening();
        for (auto &t:threads)
            t.join();
        server.stop();
    }

    void device_client(std::string server_address, int port, int duration){
        Client client;
        if (port==0){
            cerr << "wrong port" << endl;
            exit(1);
        }
        for (int i = 0; i<100; i ++) {
            if (!client.init(server_address, port)) {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cerr << "failed to connect to " << server_address << ":" << port;
                if (i > 20 ) {
                    cerr << "aborted" << endl;
                    exit(1);
                } else {
                    LOG ("retry " << i );
                    cerr << "retry " << i << endl;
                }

            } else {
                break;

            }
        }
        Virtual_device vd;
        if (!vd.init(client.device_names)){
            cerr << "failed to create virtual device" << endl;
            exit(1);
        }
        client.listen();
        std::thread t(receive_event, ref(client), ref(vd) );

        if (duration <= 0) while (true);
        this_thread::sleep_for(chrono::milliseconds(duration * 1000));

        client.stop_listening();
        vd.stop();
        t.join();
    }

    void device_client(std::string server_address, int port) {
        device_client (server_address, port, -1);
    }

    Cmd_parameters::Cmd_parameters(int c, char **s) {
        argc = c;
        args = s;
    }

    Cmd_parameter Cmd_parameters::operator[](const std::string& name) {
        Cmd_parameter cp;
        cp._name = name;
        for (int i=0; i < argc; i++){
            if (_is_parameter(args[i]) && name == args[i]) {
                cp._present = true;
                cp.empty = true;
                int j=1;
                while (i+j<argc && !_is_parameter(args[i+j])){
                    cp.empty = false;
                    cp.content.emplace_back(args[i + j]);
                    j++;
                }
                return cp;
            }
        }
        return cp;
    }

    Cmd_parameter Cmd_parameters::operator[](unsigned int index) {
        Cmd_parameter cp;
        cp._name = "position " + std::to_string(index);
        if (index>=argc) return cp;
        cp._present = true;
        cp.content.emplace_back(args[index]);
        return cp;
    }

    bool Cmd_parameter::present() {
        return _present;
    }

    int64_t Cmd_parameter::int_value(int64_t d) {
        if (_present) {
            return strtoimax(content[0].c_str(), NULL, 10);
        }
        return d;
    }

    std::string Cmd_parameter::value(std::string d) {
        if (_present) return content[0];
        return d;
    }

    double Cmd_parameter::double_value(double d) {
        if (_present) return strtod(content[0].c_str(), NULL);
        return d;
    }

    std::string Cmd_parameter::value() {
        return value("");
    }

    int64_t Cmd_parameter::int_value() {
        return int_value(0);
    }

    bool Cmd_parameter::file_exist(const std::string& extension) {
        struct stat buffer{};
        return stat((content[0] + extension).c_str(), &buffer) == 0;
    }

    bool Cmd_parameter::file_exist() {
        return file_exist("");
    }

    bool Cmd_parameter::range(double min, double max) {
        double  v = double_value();
        return v>=min && v<=max;
    }

    double Cmd_parameter::double_value() {
        return double_value(0);
    }

    Cmd_parameter &Cmd_parameter::default_value(std::string value) {
        if (!present())content[0] = value;
        return *this;
    }

    Cmd_parameter &Cmd_parameter::default_value(int value) {
        return default_value(std::to_string(value));
    }

    Cmd_parameter &Cmd_parameter::check_present() {
        return check_present("Missing parameter: " + _name);
    }

    Cmd_parameter &Cmd_parameter::check_present(const std::string& message) {
        if (!present()) {
            cerr << message << endl;
            exit(0);
        }
        return *this;
    }

    Cmd_parameter &Cmd_parameter::check_file_exist(const std::string& extension ,const std::string& message) {
        if (!file_exist(extension)) {
            cerr << message << endl;
            exit(0);
        }
        return *this;
    }

    Cmd_parameter &Cmd_parameter::check_file_exist(const std::string& extension) {
        return check_file_exist(extension, "File " + content[0] + extension + " not found.");
    }

    Cmd_parameter &Cmd_parameter::check_range(int min, int max, const std::string& message) {
        if (!range(min, max)){
            cerr << message << endl;
            exit(0);
        }
        return *this;
    }

    Cmd_parameter &Cmd_parameter::check_range(int min, int max) {
        return check_range(min, max, "Parameter " + _name + " value " + content[0] + " not within " + std::to_string(min) + "-" + std::to_string(max) + " range.");
    }

    Cmd_parameter::operator std::string() {
        return content[0];
    }

    Cmd_parameter::operator double() {
        return double_value();
    }

    unsigned int Cmd_parameter::count() {
        return content.size();
    }

    Cmd_parameter Cmd_parameter::operator[](unsigned int index) {
        Cmd_parameter cp;
        cp._name = _name;
        if (index < count()) {
            cp._present = _present;
            cp.empty = empty;
            for (int i=index; i<count() ;i++) {
                cp.content.push_back(content[i]);
            }
        } else {
            cp._present = false;
            cp.empty = true;
        }
        return cp;
    }

    bool Cmd_parameters::_is_parameter(std::string candidate) {
        return candidate[0]=='-';
    }

}