#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;


int main(int argc, char** args) {
    Cmd_parameters params(argc, args);

    if (params["-l"].present()) {
        if (params["-l"].empty) {
            device_list();
        }else {
            int device_index = params["-l"].int_value();
            device_list(device_index);
        }
        exit(0);
    }
    if (params["-d"].present()) {
        if (!params["-d"].empty) {
            device_display(params["-d"].content);
        }
        else {
            exit(1);
        }
        exit(0);
    }
    if (params["-t"].present()) {
        if (!params["-t"].empty) {
            device_test(params["-t"].value(), params["-t"][1].int_value(10));
        }
        else {
            exit(1);
        }
        exit(0);
    }
    if (params["-s"].present()) {
        if (!params["-s"].empty) {
            int duration = params["-s"][1].int_value(0);
            if (duration>0)
                device_server(params["-s"].int_value(), params["-s"][2].content, params["-s"][1].int_value());
            else
                device_server(params["-s"].int_value(), params["-s"][1].content, 0);
        }
        else {
            exit(1);
        }
        exit(0);
    }
    if (params["-c"].present()) {
        if (!params["-c"].empty) {
            if (params["-c"].count()==3) {
                int duration = params["-c"][2].int_value(0);
                device_client(params["-c"].value(), params["-c"][1].int_value(), duration);
            }else {
                device_client(params["-c"].value(), params["-c"][1].int_value());
            }
        }
        else {
            exit(1);
        }
        exit(0);
    }
    if (params["-1"].present()){
        cout << "message size: " << sizeof(Event_data) << endl;
        exit(0);
    }
    cerr << "wrong parameters" << endl;
    exit(1);
}
