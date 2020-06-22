#include <virtual_device.h>
#include <iostream>
#include <fcntl.h>


using namespace std;

namespace moukey {

    bool Virtual_device::init(std::string name) {

        dev = libevdev_new();
        libevdev_set_name(dev, name.c_str());

        for (int i = 0; i <= EV_MAX; i++)
            libevdev_enable_event_type(dev, i);
        for (int j = 0; j < KEY_MAX; j++)
            libevdev_enable_event_code(dev, EV_KEY, j, NULL);
        for (int j = 0; j < REL_MAX; j++)
            libevdev_enable_event_code(dev, EV_REL, j, NULL);
        for (int j = 0; j < ABS_MAX; j++)
            libevdev_enable_event_code(dev, EV_ABS, j, NULL);
        for (int j = 0; j < LED_MAX; j++)
            libevdev_enable_event_code(dev, EV_LED, j, NULL);

        return libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev) == 0;
    }

    void Virtual_device::dispatch(const Event &event) {
        libevdev_uinput_write_event(uidev, event.event.type, event.event.code, event.event.value);
    }

    void Virtual_device::stop() {
        libevdev_uinput_destroy(uidev);
    }
}