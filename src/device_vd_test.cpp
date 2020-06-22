#include <virtual_device.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    Virtual_device vd;
    Event e;
    if (!vd.init("moukey virtual device")){
        cout <<"ERROR" <<endl;
        exit(1);
    }
    e.event.type=EV_KEY;
    e.event.code=KEY_H;
    e.event.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event.type=EV_KEY;
    e.event.code=KEY_H;
    e.event.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event.type=EV_KEY;
    e.event.code=KEY_E;
    e.event.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event.type=EV_KEY;
    e.event.code=KEY_E;
    e.event.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event.type=EV_KEY;
    e.event.code=KEY_L;
    e.event.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event.type=EV_KEY;
    e.event.code=KEY_L;
    e.event.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event.type=EV_KEY;
    e.event.code=KEY_L;
    e.event.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event.type=EV_KEY;
    e.event.code=KEY_L;
    e.event.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event.type=EV_KEY;
    e.event.code=KEY_O;
    e.event.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event.type=EV_KEY;
    e.event.code=KEY_O;
    e.event.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(350) );
    vd.stop();
    cout << endl;
}