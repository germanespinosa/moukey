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
        Event event;
        bool listening;
    };
}