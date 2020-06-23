#include <dirent.h>
#include <iostream>
#include <event.h>


using namespace std;

namespace moukey {

    std::ostream &operator<<(ostream &out, const Event &e) {
        out << "type: " << e.type() << "\tcode: " << e.code() << "\tvalue: " << e.value();
        return out;
    }

    std::string Event::type() const {
        return libevdev_event_type_get_name(event_data.type);
    }

    std::string Event::code() const {
        return libevdev_event_code_get_name(event_data.type, event_data.code);
    }

    int32_t Event::value() const {
        return event_data.value;
    }
}