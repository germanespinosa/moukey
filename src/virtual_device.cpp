#include <virtual_device.h>
#include <iostream>
#include <fcntl.h>

using namespace std;

namespace moukey {

    bool Virtual_device::init(const std::vector<std::string> &d_n) {
        device_names = d_n;
        for (string device_name:device_names) {
            auto new_dev = libevdev_new();
            dev.push_back(new_dev);
            libevdev_set_name(new_dev, device_name.c_str());
            for (int i = 0; i <= EV_MAX; i++)
                libevdev_enable_event_type(new_dev, i);
            for (int j = 0; j < KEY_MAX; j++)
                libevdev_enable_event_code(new_dev, EV_KEY, j, NULL);
            for (int j = 0; j < REL_MAX; j++)
                libevdev_enable_event_code(new_dev, EV_REL, j, NULL);
            for (int j = 0; j < ABS_MAX; j++)
                libevdev_enable_event_code(new_dev, EV_ABS, j, NULL);
            for (int j = 0; j < LED_MAX; j++)
                libevdev_enable_event_code(new_dev, EV_LED, j, NULL);
            libevdev_uinput *new_uidev;
            if (libevdev_uinput_create_from_device(new_dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &new_uidev)){
                return false;
            }
            uidev.push_back(new_uidev);
        }
        return true;
    }

    void Virtual_device::dispatch(int device_index, const Event &event) {
        libevdev_uinput_write_event(uidev[device_index], event.data.type, event.data.code, event.data.value);
    }

    void Virtual_device::stop() {
        for (int i = 0; i<device_names.size();i++)
            libevdev_uinput_destroy(uidev[i]);
    }
}