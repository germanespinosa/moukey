#pragma once
#include <libevdev/libevdev.h>
#include <string>
#include <vector>

namespace moukey {
    struct Event {
        std::string type() const;
        std::string code() const;
        int32_t value() const;
        input_event event;
        friend std::ostream& operator<<(std::ostream& , const Event& );
    };
};