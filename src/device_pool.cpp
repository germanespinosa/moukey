#include <device_pool.h>
#include <string>
#include <fcntl.h>
#include <dirent.h>
#include <iostream>
#include <utility>

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
        device_path(std::move(device_path)){
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

    bool Device_pool::init(const std::string& device_name) {
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

    bool Device_pool::init(const vector<string>& device_names) {
        struct dirent *entry;
        DIR *dir = opendir(device_path.c_str());
        if (dir == NULL) {
            return false;
        }
        while ((entry = readdir(dir)) != NULL) {
            string file_path = device_path + string(entry->d_name);
            Device d(file_path);
            for (auto &device_name: device_names) {
                if (d.init() && d.name() == device_name) {
                    devices.push_back(d);
                    break;
                }
            }
        }
        closedir(dir);
        return true;
    }

    Device &Device_pool::operator[](unsigned int index) {
        return devices[index];
    }
}