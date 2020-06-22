#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;


int main(int argc, char** args) {
    switch (argc){
        case 1:
            device_list();
            break;
        case 2:
            device_list((unsigned int)stoi(args[1]));
            break;
        default:
            //error
            cerr << "wrong parameters" << endl;
            exit(1);
    }

}