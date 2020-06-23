#include <device_pool.h>
#include <fcntl.h>
#include <dirent.h>
#include <iostream>
#include <util.h>

using namespace std;

namespace moukey{
    Device::Device(string path):
            path(path), handler(NULL) {}

    bool Device::init()
    {
        int fd;
        int rc = 1;
        LOG("opening device at "+ path);
        fd = open(path.c_str(), O_RDONLY|O_NONBLOCK);
        if (fd==0) {
            cerr << "failed to open device at " << path << endl;
            return false;
        }
        LOG("successfully opened " + path);
        LOG("creating livevdev handler");
        rc = libevdev_new_from_fd(fd, &handler);
        if (rc < 0) {
            cerr << "failed to create livev handler" <<  endl;
            return false;
        }
        LOG("successfully created livevdev handler");
        LOG("querying supported events");
        for (int i = 0; i <= EV_MAX; i++) {
            if (libevdev_has_event_type(handler, i)) {
                LOG("supported event found");
                supported_events.push_back(i);
            }
        }
        LOG("finished querying supported events");
        return true;
    }

    string Device::name() const {
        auto p = libevdev_get_name(handler);
        return p?p:"";
    }

    string Device::physical() const {
        auto p = libevdev_get_phys(handler);
        return p?p:"";
    }

    ostream &operator<<(ostream &out, const Device &d) {
        out << "name: " << d.name() << endl;
        out << "physical: " << d.physical() << endl;
        auto id = d.id();
        if (!id.empty()) out << "id: " << id << endl;
        out << "supported event types: ";
        for (auto e:d.supported_events)
            out << libevdev_event_type_get_name(e) << " ";
        out << endl;
        return out;
    }

    std::string Device::id() const {
        auto p = libevdev_get_uniq(handler);
        return p?p:"";
    }

    int Device::driver_version() const {
        return libevdev_get_driver_version(handler);
    }

    void Device::list_supported_events() const {
        for (auto e:supported_events)
            cout << libevdev_event_type_get_name(e) << endl;
    }

    void Device::grab() {
        libevdev_grab(handler, LIBEVDEV_GRAB);
    }

    bool Device::wait_for_event() {
        int rc = 0;
        input_event ev{};
        while (listening) {
            rc = libevdev_next_event(handler, LIBEVDEV_READ_FLAG_NORMAL, &ev);
            if (rc == 0) {
                event.data.type = ev.type;
                event.data.code = ev.code;
                event.data.value = ev.value;
                return true;
            }
            if (!(rc == 1 || rc == 0 || rc == -EAGAIN)) {
                release();
                return false;
            }
        }
        return false;
    }

    void Device::release() {
        libevdev_grab(handler, LIBEVDEV_UNGRAB);
    }

    void Device::listen() {
        grab();
        listening = true;
    }

    void Device::stop_listening() {
        listening = false;
    }
}