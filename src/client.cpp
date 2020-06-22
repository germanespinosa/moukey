#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <client.h>


using namespace std;

namespace moukey {

    bool moukey::Client::init(std::string a, int p) {
        port = p;
        if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return false;
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        if(inet_pton(AF_INET, a.c_str(), &address.sin_addr)<=0) return false;
        if (connect(fd, (struct sockaddr *)&address, sizeof(address)) < 0) return false;
    }

    void Client::stop_listening() {
        listening = false;
        close(fd);
    }

    bool Client::wait_for_event() {
        while (listening){
            try{
                int res = read(fd, &event.event, sizeof(input_event));
                if (res == sizeof(input_event)){
                    return true;
                }
                return false;
            }
            catch (int e){
                return false;
            }
        }
        return false;
    }

    void Client::listen() {
        listening = true;
    }
}