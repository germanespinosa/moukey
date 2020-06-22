#include <server.h>
#include <device_pool.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace moukey;

Server server;

void print_events(Device &d){
    d.listen();
    while (d.wait_for_event()) {
        server.dispatch(d.event);
    }
}

int main(int argc, char** args) {
    if (argc!=3){
        exit(1);
    }
    int port = stoi(args[1]);
    if (port==0){
        exit(1);
    }
    Device_pool dp;
    dp.init(args[2]);
    if (dp.devices.empty()) {
        exit(1);
    }

    server.start(port);
    cout << dp[0];

    std::thread t(print_events, ref(dp[0]));
    this_thread::sleep_for(chrono::milliseconds(30000) );
    dp[0].stop_listening();
    t.join();
    server.stop();
    cout << endl;
}