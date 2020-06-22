#include <moukey.h>
#include <iostream>


using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    if (argc!=3){
        exit(1);
    }
    string server_address = args[1];
    int port = stoi(args[2]);
    if (port==0){
        exit(1);
    }
    device_client(server_address, port, 30);
}