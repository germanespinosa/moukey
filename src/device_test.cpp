#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    if (argc!=2){
        exit(1);
    }
    device_test(args[1], 10);
}