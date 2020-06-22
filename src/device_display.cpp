#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;


int main(int argc, char** args) {
    if (argc==1){
        exit(1);
    }
    vector<string> device_names;
    for (int p=1; p<argc; p++) {
        device_names.emplace_back(args[p]);
    }
    device_display(device_names);
}