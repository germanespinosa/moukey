#include <device_pool.h>
#include <virtual_device.h>
#include <server.h>
#include <client.h>

namespace moukey {
    struct Cmd_parameter{
        bool present();
        bool file_exist();
        bool file_exist(const std::string&);
        bool range(double, double);
        int64_t int_value(int64_t);
        int64_t int_value();
        std::string value(std::string);
        std::string value();
        double double_value(double);
        double double_value();
        Cmd_parameter & default_value(std::string);
        Cmd_parameter & default_value(int);
        Cmd_parameter & check_present(const std::string&);
        Cmd_parameter & check_present();
        Cmd_parameter & check_file_exist(const std::string&, const std::string&);
        Cmd_parameter & check_file_exist(const std::string&);
        Cmd_parameter & check_range(int, int, const std::string&);
        Cmd_parameter & check_range(int, int);
        Cmd_parameter operator [](unsigned int);
        unsigned int count();
        operator std::string();
        operator double ();
        bool empty;
        std::vector<std::string> content;
    private:
        std::string _name;
        bool _present = false;
        friend class Cmd_parameters;
    };

    struct Cmd_parameters{
        Cmd_parameters(int, char **);
        Cmd_parameter operator [](const std::string&);
        Cmd_parameter operator [](unsigned int);
    private:
        bool _is_parameter(std::string);
        int argc;
        char **args;
    };

    void device_list();
    void device_list(unsigned int);
    void device_display(const std::string &);
    void device_display(const std::vector<std::string>&);
    void device_server(int, std::vector<std::string>, int);
    void device_server(int, std::vector<std::string>);
    void device_server(int);
    void device_server(int, int);
    void device_client(std::string, int, int);
    void device_client(std::string, int);
    void device_test(const std::vector<std::string> &, int);
}