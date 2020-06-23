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
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_H;
    e.event_data.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_H;
    e.event_data.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_E;
    e.event_data.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_E;
    e.event_data.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_L;
    e.event_data.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_L;
    e.event_data.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_L;
    e.event_data.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_L;
    e.event_data.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(20) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_O;
    e.event_data.value=1;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(80) );
    e.event_data.type=EV_KEY;
    e.event_data.code=KEY_O;
    e.event_data.value=0;
    vd.dispatch(e);
    this_thread::sleep_for(chrono::milliseconds(350) );
    vd.stop();
    cout << endl;
}