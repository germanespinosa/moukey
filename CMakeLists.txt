cmake_minimum_required(VERSION 3.0)
project(moukey)

set(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_CXX_STANDARD 14)


add_library(moukey_lib
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


if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DVERBOSE=1)

    add_executable(moukey_l
            src/device_list.cpp)

    target_link_libraries(moukey_l moukey_lib
            ${EVDEV_LIBRARIES})

    add_executable(moukey_d
            src/device_display.cpp src/server.cpp)

    target_link_libraries(moukey_d moukey_lib
            ${EVDEV_LIBRARIES})

    add_executable(moukey_t
            src/device_test.cpp)

    target_link_libraries(moukey_t moukey_lib
            ${EVDEV_LIBRARIES})

    add_executable(moukey_s
            src/device_server.cpp)

    target_link_libraries(moukey_s moukey_lib
            ${EVDEV_LIBRARIES})

    add_executable(moukey_c
            src/device_client.cpp)

    target_link_libraries(moukey_c moukey_lib
            ${EVDEV_LIBRARIES})

    add_executable(moukey_v
            src/device_vd_test.cpp)

    target_link_libraries(moukey_v moukey_lib
            ${EVDEV_LIBRARIES})
endif()

add_executable(moukey
        main.cpp include/util.h)

target_link_libraries(moukey moukey_lib
        ${EVDEV_LIBRARIES})

install(TARGETS moukey
        RUNTIME  DESTINATION bin
        DESTINATION bin )

install(DIRECTORY scripts/ DESTINATION bin)
install(CODE "execute_process(COMMAND chmod +x ${CMAKE_INSTALL_PREFIX}/bin/moukey_run)")
install(CODE "execute_process(COMMAND chmod +x ${CMAKE_INSTALL_PREFIX}/bin/moukey_register)")
install(CODE "execute_process(COMMAND chmod +x ${CMAKE_INSTALL_PREFIX}/bin/moukey_server)")
install(CODE "execute_process(COMMAND chmod +x ${CMAKE_INSTALL_PREFIX}/bin/moukey_client)")

install(CODE "execute_process(COMMAND moukey_register ${CMAKE_INSTALL_PREFIX}/bin)")
install(CODE "execute_process(COMMAND chmod +x ${CMAKE_INSTALL_PREFIX}/bin/moukey_location)")
