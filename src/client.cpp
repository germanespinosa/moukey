#include <util.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <client.h>


using namespace std;

namespace moukey {

    bool moukey::Client::init(std::string a, int p) {
        port = p;
        if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return false;
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        if(inet_pton(AF_INET, a.c_str(), &address.sin_addr)<=0) return false;
        if (connect(fd, (struct sockaddr *)&address, sizeof(address)) < 0) return false;
        LOG("connected");
        int device_count = 0;
        read(fd, &device_count, sizeof(uint16_t));
        char buffer[1024];
        LOG(device_count << " devices served");
        for (int d = 0;d<device_count;d++){
            int device_name_size = 0;
            read(fd, &device_name_size, sizeof(uint16_t));
            int msg_len = read(fd, buffer, device_name_size);
            if (msg_len == device_name_size){
                buffer[msg_len]= 0;
                LOG(buffer );
                device_names.emplace_back(buffer);
            }
        }
        LOG("client ready");
        return true;
    }

    void Client::stop_listening() {
        listening = false;
        close(fd);
    }

    bool Client::wait_for_event() {
        while (listening){
            try{
                int res = read(fd, &device_ind, sizeof(int16_t));
                if (res == sizeof(int16_t)) {
                    res = read(fd, &event.data, sizeof(Event_data));
                    if (res == sizeof(Event_data)) {
                        return true;
                    }
                }
                if (res) {
                    cerr << "wrong message size :" << res << endl;
                } else {
                    LOG ("disconnected");
                }
                return false;
            }
            catch (int e){
                cerr << "error receiving message:" << e << endl;
                return false;
            }
        }
        return false;
    }

    void Client::listen() {
        listening = true;
    }
}