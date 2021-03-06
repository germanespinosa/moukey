#include <poll.h>
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <server.h>
#include <mutex>
#include <util.h>

using namespace std;

namespace moukey {

    bool Server::start(int p) {
        port = p;
        int opt = 1;

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

    mutex mtx;
    bool moukey::Server::dispatch_event(int16_t device_ind, const moukey::Event &event) {
        mtx.lock();
        LOG ("sending event from device " << device_ind);
        if (send_data((void *) &device_ind, sizeof(int16_t))) {
            if (send_data((void *) &event.data, sizeof(Event_data))){
                mtx.unlock();
                return true;
            }
        }
        mtx.unlock();
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
                    cout << "new connection" << endl;
                    server.send_devices_info(new_socket);
                    if (new_socket>=0) server.connections.push_back(new_socket);
                    server.active_connection = 0;
                }
            }
            catch (int e){
            }
        }
    }

    Server::Server( const std::vector<std::string> &device_names):
        device_names(device_names),
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

    bool Server::send_data(int client_fd, const void *data, uint16_t size) {
        ssize_t l = 0;
        try {
            LOG("sending " << size << " bytes");
            l = send(client_fd, data, size, 0);
        } catch (int e){
            l = 0;
        }
        if ( l != size){
            close(client_fd);
            active_connection = -1;
            return false;
        }
        return true;
    }

    bool Server::send_data(const void *data, uint16_t size) {
        if (active_connection>=0){
            ssize_t l = 0;
            if (!send_data(connections[active_connection], data,size)){
                connections.erase(connections.begin() + active_connection);
                active_connection = -1;
                return false;
            }
            return true;
        }
        return false;
    }

    void Server::send_devices_info(int new_socket) {
        uint16_t count = device_names.size();
        LOG("serving "<< count << " devices");
        send_data(new_socket, &count, sizeof(uint16_t));
        for (int i=0; i<count; i++){
            auto device_name = device_names[i];
            uint16_t size = device_name.size();
            LOG("sending " << size << " " << device_name);
            send_data(new_socket, &size, sizeof(uint16_t));
            send_data(new_socket, device_name.c_str(), size);
        }
    }
}