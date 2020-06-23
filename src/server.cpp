#include <poll.h>
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <server.h>
#include <mutex>

using namespace std;

namespace moukey {

    bool Server::start(int p) {
        port = p;
        int opt = 1;
        char buffer[1024] = {0};

        if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) return false;
        if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) return false;

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        // Forcefully attaching socket to the port 8080
        if (bind(fd, (struct sockaddr *) &address,sizeof(address)) < 0) return false;
        if (listen(fd, 3) < 0) return false;

        running = true;
        _server_t = thread(Server::_server, ref(*this));
        return true;
    }

    bool moukey::Server::dispatch(const moukey::Event &event) {
        if (active_connection>=0){
            ssize_t l = 0;
            try {
                mutex mtx;
                l = send(connections[active_connection], (void *) &event.event, sizeof(input_event), 0);
            } catch (int e){
                l = 0;
            }
            if ( l != sizeof(input_event)){
                close(connections[active_connection]);
                connections.erase(connections.begin() + active_connection);
                active_connection = -1;
                return false;
            }
            return true;
        }
        return false;
    }

    void Server::_server(Server &server) {
        int new_socket;
        pollfd pfd{server.fd,POLLIN,0};
        while (server.running){
            try{
                int res = poll (&pfd, 1,1000);
                if (server.running && pfd.revents & POLLIN) {
                    new_socket = accept(server.fd, NULL, 0);
                    cout << "new connection" <<  endl;
                    if (new_socket>=0) server.connections.push_back(new_socket);
                    server.active_connection = 0;
                }
            }
            catch (int e){
            }
        }
    }

    Server::Server():
    active_connection(-1){

    }

    void Server::next_connection() {
        if (connections.empty()) return;
        if (active_connection == connections.size()-1) active_connection = 0;
        else active_connection ++;
    }

    void Server::previous_connection() {
        if (connections.empty()) return;
        if (active_connection == 0) active_connection = (int)connections.size()-1;
        else active_connection --;
    }

    void Server::stop() {
        running = false;
        close(fd);
        _server_t.join();
    }
}