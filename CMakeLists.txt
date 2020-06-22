cmake_minimum_required(VERSION 3.16)
project(moukey)

set(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_CXX_STANDARD 14)


add_library(moukey
        src/event.cpp
        src/device.cpp
        src/device_pool.cpp
        src/server.cpp
        src/client.cpp
        src/virtual_device.cpp src/moukey.cpp include/moukey.h)

find_package(PkgConfig REQUIRED)

pkg_search_module(EVDEV REQUIRED libevdev)

include_directories(
        ${EVDEV_INCLUDE_DIRS}
        include/)

add_executable(moukey_l
        src/device_list.cpp)

target_link_libraries(moukey_l moukey
        ${EVDEV_LIBRARIES})

add_executable(moukey_d
        src/device_display.cpp src/server.cpp)

target_link_libraries(moukey_d moukey
        ${EVDEV_LIBRARIES})

add_executable(moukey_t
        src/device_test.cpp)

target_link_libraries(moukey_t moukey
        ${EVDEV_LIBRARIES})

add_executable(moukey_s
        src/device_server.cpp)

target_link_libraries(moukey_s moukey
        ${EVDEV_LIBRARIES})

add_executable(moukey_c
        src/device_client.cpp)

target_link_libraries(moukey_c moukey
        ${EVDEV_LIBRARIES})

add_executable(moukey_v
        src/device_vd_test.cpp)

target_link_libraries(moukey_v moukey
        ${EVDEV_LIBRARIES})

