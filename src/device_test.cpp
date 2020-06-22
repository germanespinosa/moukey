#include <device_pool.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace moukey;

void print_events(Device &d){
    d.listen();
    while (d.wait_for_event()) {
        cout << d.event << endl;
    }
}

int main(int argc, char** args) {
    if (argc!=2){
        exit(1);
    }
    Device_pool dp;
    dp.init(args[1]);
    if (dp.devices.empty()) {
        exit(1);
    }
    cout << dp[0];
    std::thread t(print_events, ref(dp[0]));
    this_thread::sleep_for(chrono::milliseconds(10000) );
    dp[0].stop_listening();
    t.join();
    cout << endl;
}