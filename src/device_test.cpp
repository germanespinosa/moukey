#include <moukey.h>
#include <iostream>

using namespace std;
using namespace moukey;

int main(int argc, char** args) {
    if (argc!=2){
        exit(1);
    }
    vector<string> names;
    names.emplace_back(args[1]);
    device_test(names, 10);
}