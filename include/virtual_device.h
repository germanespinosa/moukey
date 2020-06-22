#pragma once
#include <event.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#include <string>
#include <vector>

namespace moukey {
    struct Virtual_device {
        bool init (std::string);
        void dispatch(const Event&);
        void stop();
        libevdev *dev;
        libevdev_uinput *uidev;
    };
}