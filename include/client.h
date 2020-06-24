#pragma once
#include <event.h>
#include <netinet/in.h>
#include <string>
#include <vector>

namespace moukey {
    struct Client {
        bool init(std::string, int);
        void listen();
        void stop_listening();
        int (*callback)(const Event &);
        sockaddr_in address;
        int port;
        int fd;
        bool wait_for_event();
        int16_t device_ind;
        Event event;
        bool listening;
        std::vector<std::string> device_names;
    };
}