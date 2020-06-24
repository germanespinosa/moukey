#pragma once
#include <event.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#include <string>
#include <vector>

namespace moukey {
    struct Virtual_device {
        bool init (const std::vector<std::string> &);
        void dispatch(int, const Event&);
        void stop();
        std::vector<libevdev *>dev;
        std::vector<libevdev_uinput *>uidev;
        std::vector<std::string> device_names;
    };
}