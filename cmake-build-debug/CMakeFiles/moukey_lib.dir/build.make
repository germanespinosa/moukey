# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/german/moukey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/german/moukey/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/moukey_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/moukey_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/moukey_lib.dir/flags.make

CMakeFiles/moukey_lib.dir/src/event.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/event.cpp.o: ../src/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/moukey_lib.dir/src/event.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/event.cpp.o -c /home/german/moukey/src/event.cpp

CMakeFiles/moukey_lib.dir/src/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/event.cpp > CMakeFiles/moukey_lib.dir/src/event.cpp.i

CMakeFiles/moukey_lib.dir/src/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/event.cpp -o CMakeFiles/moukey_lib.dir/src/event.cpp.s

CMakeFiles/moukey_lib.dir/src/device.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/device.cpp.o: ../src/device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/moukey_lib.dir/src/device.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/device.cpp.o -c /home/german/moukey/src/device.cpp

CMakeFiles/moukey_lib.dir/src/device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/device.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/device.cpp > CMakeFiles/moukey_lib.dir/src/device.cpp.i

CMakeFiles/moukey_lib.dir/src/device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/device.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/device.cpp -o CMakeFiles/moukey_lib.dir/src/device.cpp.s

CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o: ../src/device_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o -c /home/german/moukey/src/device_pool.cpp

CMakeFiles/moukey_lib.dir/src/device_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/device_pool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/device_pool.cpp > CMakeFiles/moukey_lib.dir/src/device_pool.cpp.i

CMakeFiles/moukey_lib.dir/src/device_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/device_pool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/device_pool.cpp -o CMakeFiles/moukey_lib.dir/src/device_pool.cpp.s

CMakeFiles/moukey_lib.dir/src/server.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/server.cpp.o: ../src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/moukey_lib.dir/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/server.cpp.o -c /home/german/moukey/src/server.cpp

CMakeFiles/moukey_lib.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/server.cpp > CMakeFiles/moukey_lib.dir/src/server.cpp.i

CMakeFiles/moukey_lib.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/server.cpp -o CMakeFiles/moukey_lib.dir/src/server.cpp.s

CMakeFiles/moukey_lib.dir/src/client.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/moukey_lib.dir/src/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/client.cpp.o -c /home/german/moukey/src/client.cpp

CMakeFiles/moukey_lib.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/client.cpp > CMakeFiles/moukey_lib.dir/src/client.cpp.i

CMakeFiles/moukey_lib.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/client.cpp -o CMakeFiles/moukey_lib.dir/src/client.cpp.s

CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o: ../src/virtual_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o -c /home/german/moukey/src/virtual_device.cpp

CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/virtual_device.cpp > CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.i

CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/virtual_device.cpp -o CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.s

CMakeFiles/moukey_lib.dir/src/moukey.cpp.o: CMakeFiles/moukey_lib.dir/flags.make
CMakeFiles/moukey_lib.dir/src/moukey.cpp.o: ../src/moukey.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/moukey_lib.dir/src/moukey.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_lib.dir/src/moukey.cpp.o -c /home/german/moukey/src/moukey.cpp

CMakeFiles/moukey_lib.dir/src/moukey.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_lib.dir/src/moukey.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/moukey.cpp > CMakeFiles/moukey_lib.dir/src/moukey.cpp.i

CMakeFiles/moukey_lib.dir/src/moukey.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_lib.dir/src/moukey.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/moukey.cpp -o CMakeFiles/moukey_lib.dir/src/moukey.cpp.s

# Object files for target moukey_lib
moukey_lib_OBJECTS = \
"CMakeFiles/moukey_lib.dir/src/event.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/device.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/server.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/client.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o" \
"CMakeFiles/moukey_lib.dir/src/moukey.cpp.o"

# External object files for target moukey_lib
moukey_lib_EXTERNAL_OBJECTS =

libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/event.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/device.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/device_pool.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/server.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/client.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/virtual_device.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/src/moukey.cpp.o
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/build.make
libmoukey_lib.a: CMakeFiles/moukey_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libmoukey_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/moukey_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/moukey_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/moukey_lib.dir/build: libmoukey_lib.a

.PHONY : CMakeFiles/moukey_lib.dir/build

CMakeFiles/moukey_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/moukey_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/moukey_lib.dir/clean

CMakeFiles/moukey_lib.dir/depend:
	cd /home/german/moukey/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/german/moukey /home/german/moukey /home/german/moukey/cmake-build-debug /home/german/moukey/cmake-build-debug /home/german/moukey/cmake-build-debug/CMakeFiles/moukey_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/moukey_lib.dir/depend

