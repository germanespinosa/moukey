#include <device_pool.h>
#include <iostream>

using namespace std;
using namespace moukey;


int main(int argc, char** args) {
    Device_pool dp;
    dp.init();
    if (argc>1){
        cout << dp.devices[stoi(args[1])].name() << endl;
    } else
        dp.list_devices();
}