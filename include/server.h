#pragma once
#include <event.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include <thread>

namespace moukey {
    struct Server {
        explicit Server(const std::vector<std::string> &);
        bool start(int);
        bool dispatch_event(const Event &);
        bool send_data(const void *, uint16_t );
        void next_connection();
        void previous_connection();
        void send_devices_info();
        sockaddr_in address;
        int port;
        std::vector<int> connections;
        bool running;
        int fd;
        int active_connection;
        void stop();
        const std::vector<std::string> &device_names;
    private:
        std::thread _server_t;
        static void _server(Server &);
    };
}