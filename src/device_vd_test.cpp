#include <virtual_device.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <util.h>

using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    LOG("HELLO!");
    exit (0);
    Virtual_device vd;
    Event e;
    if (!vd.init("moukey virtual device")){
        cout <<"ERROR" <<endl;
        exit(1);
    }
    e.data.set_data(EV_KEY, KEY_H,1);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_H,0);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_E,1);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_E,0);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_L,1);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_L,0);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_L,1);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_L,0);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_O,1);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_O,0);
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(350) );
    vd.stop();
    cout << endl;
}