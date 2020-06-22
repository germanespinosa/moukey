#include <device_pool.h>
#include <virtual_device.h>
#include <server.h>
#include <client.h>

namespace moukey {
    void device_list();
    void device_list(std::string);
    void device_display(std::vector<std::string>);
    void device_server(int, std::vector<std::string>);
    void device_client(std::string, int);
    void device_test(std::string);
}