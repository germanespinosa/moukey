#include <virtual_device.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <util.h>

using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    Virtual_device vd;
    Event e;
    vector<string> names;
    names.push_back("moukey virtual device");
    if (!vd.init(names)){
        cout <<"ERROR" <<endl;
        exit(1);
    }
    e.data.set_data(EV_KEY, KEY_H,1);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_H,0);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_E,1);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_E,0);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_L,1);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_L,0);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_L,1);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_L,0);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.data.set_data(EV_KEY, KEY_O,1);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.data.set_data(EV_KEY, KEY_O,0);
    vd.dispatch(0,e);
    this_thread::sleep_for(chrono::milliseconds(350) );
    vd.stop();
    cout << endl;
}