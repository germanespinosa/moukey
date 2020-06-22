#include <client.h>
#include <virtual_device.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace moukey;

Client client;
Virtual_device vd;
void print_events(){
    while (client.wait_for_event()) {
        vd.dispatch(client.event);
    }
}

int main(int argc, char** args) {
    if (argc!=3){
        exit(1);
    }
    string server_address = args[1];
    int port = stoi(args[2]);
    if (port==0){
        exit(1);
    }
    vd.init("moukey virtual device");
    client.init(server_address, port);
    client.listen();
    std::thread t(print_events);
    this_thread::sleep_for(chrono::milliseconds(10000) );
    client.stop_listening();
    vd.stop();
    t.join();
}