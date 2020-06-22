#include <device_pool.h>
#include <string>
#include <fcntl.h>
#include <dirent.h>
#include <iostream>

using namespace std;

namespace moukey{

    void Device_pool::list_devices() {
        int ind=0;
        for (auto d:devices){
            cout << ind << ": " << d.name() << endl;
            ind ++;
        }
    }

    void Device_pool::capture_all() {

    }

    Device_pool::Device_pool() :
        Device_pool("/dev/input/"){

    }

    Device_pool::Device_pool(string device_path):
        device_path(device_path){
    }

    bool Device_pool::init() {
        struct dirent *entry;
        DIR *dir = opendir(device_path.c_str());
        if (dir == NULL) {
            return false;
        }
        while ((entry = readdir(dir)) != NULL) {
            string file_path = device_path + string(entry->d_name);
            Device d(file_path);
            if (d.init())
                devices.push_back(d);
        }
        closedir(dir);
        return true;
    }

    bool Device_pool::init(std::string device_name) {
        struct dirent *entry;
        DIR *dir = opendir(device_path.c_str());
        if (dir == NULL) {
            return false;
        }
        while ((entry = readdir(dir)) != NULL) {
            string file_path = device_path + string(entry->d_name);
            Device d(file_path);
            if (d.init() && d.name() == device_name)
                devices.push_back(d);
        }
        closedir(dir);
        return true;
    }

    Device &Device_pool::operator[](int index) {
        return devices[index];
    }
}