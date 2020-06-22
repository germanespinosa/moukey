#pragma once
#include <device.h>
#include <string>
#include <vector>

namespace moukey {
    struct Device_pool {
        explicit Device_pool(std::string);
        Device_pool();
        bool init();
        bool init(std::string);
        void list_devices();
        void capture_all();
        std::vector<Device> devices;
        std::string device_path;
        Device &operator [](int);
    };
};