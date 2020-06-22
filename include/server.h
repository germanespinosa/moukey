#pragma once
#include <event.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include <thread>

namespace moukey {
    struct Server {
        Server();
        bool start(int);
        void dispatch(const Event &);
        void next_connection();
        void previous_connection();
        sockaddr_in address;
        int port;
        std::vector<int> connections;
        bool running;
        int fd;
        int active_connection;
        void stop();
    private:
        std::thread _server_t;
        static void _server(Server &);
    };
}