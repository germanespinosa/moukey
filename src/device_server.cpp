#include <server.h>
#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    if (argc<3){
        exit(1);
    }
    int port = stoi(args[1]);
    if (port==0){
        exit(1);
    }
    vector<string> device_names;
    for (int i=2;i<argc;i++)
        device_names.emplace_back(args[i]);

    device_server(port,device_names,20);
}