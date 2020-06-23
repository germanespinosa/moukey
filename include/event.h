#pragma once
#include <libevdev/libevdev.h>
#include <string>
#include <vector>

namespace moukey {
    struct Event_data{
        uint16_t type;
        uint16_t  code;
        int32_t  value;
    };
    struct Event {
        std::string type() const;
        std::string code() const;
        int32_t value() const;
        Event_data event_data;
        friend std::ostream& operator<<(std::ostream& , const Event& );
    };
};