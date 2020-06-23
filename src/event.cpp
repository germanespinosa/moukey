#include <dirent.h>
#include <iostream>
#include <event.h>


using namespace std;

namespace moukey {

    std::ostream &operator<<(ostream &out, const Event &e) {
        out << "type: "<< e.data.type << "(" << e.type() << ")\tcode: " << e.data.code << "(" << e.code() << ")\tvalue: " << e.value();
        return out;
    }

    std::string Event::type() const {
        return libevdev_event_type_get_name(data.type);
    }

    std::string Event::code() const {
        return libevdev_event_code_get_name(data.type, data.code);
    }

    int32_t Event::value() const {
        return data.value;
    }

    void Event_data::set_data(uint16_t t, uint16_t c, int32_t v) {
        type = t;
        code = c;
        value = v;
    }
}