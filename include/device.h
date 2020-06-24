#pragma once
#include <event.h>
#include <libevdev/libevdev.h>
#include <string>
#include <vector>

namespace moukey {
    struct Device {
        explicit Device(std::string);
        bool init();
        bool wait_for_event();
        std::string name() const;
        std::string physical() const;
        std::string id() const;
        void listen ();
        void stop_listening();
        void grab();
        void release();
        void list_supported_events() const;
        int driver_version() const;
        std::string path;
        libevdev *handler;
        Event event;
        uint16_t index;
        std::vector<int> supported_events;
        bool listening;
        friend std::ostream& operator<<(std::ostream& , const Device& );
    };
};