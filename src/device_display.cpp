#include <device_pool.h>
#include <iostream>

using namespace std;
using namespace moukey;


int main(int argc, char** args) {
    if (argc==1){
        exit(1);
    }
    Device_pool dp;
    unsigned int size = 0;
    for (int p=1; p<argc; p++) {
        dp.init(args[p]);
        if (dp.devices.size() == size) {
            exit(1);
        }
        cout << dp[size] << endl;
        size ++;
    }
}