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
CMAKE_COMMAND = /opt/clion-2019.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/german/moukey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/german/moukey/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/moukey_d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/moukey_d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/moukey_d.dir/flags.make

CMakeFiles/moukey_d.dir/src/device_display.cpp.o: CMakeFiles/moukey_d.dir/flags.make
CMakeFiles/moukey_d.dir/src/device_display.cpp.o: ../src/device_display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/moukey_d.dir/src/device_display.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_d.dir/src/device_display.cpp.o -c /home/german/moukey/src/device_display.cpp

CMakeFiles/moukey_d.dir/src/device_display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_d.dir/src/device_display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/device_display.cpp > CMakeFiles/moukey_d.dir/src/device_display.cpp.i

CMakeFiles/moukey_d.dir/src/device_display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_d.dir/src/device_display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/device_display.cpp -o CMakeFiles/moukey_d.dir/src/device_display.cpp.s

CMakeFiles/moukey_d.dir/src/server.cpp.o: CMakeFiles/moukey_d.dir/flags.make
CMakeFiles/moukey_d.dir/src/server.cpp.o: ../src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/moukey_d.dir/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/moukey_d.dir/src/server.cpp.o -c /home/german/moukey/src/server.cpp

CMakeFiles/moukey_d.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/moukey_d.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/german/moukey/src/server.cpp > CMakeFiles/moukey_d.dir/src/server.cpp.i

CMakeFiles/moukey_d.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/moukey_d.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/german/moukey/src/server.cpp -o CMakeFiles/moukey_d.dir/src/server.cpp.s

# Object files for target moukey_d
moukey_d_OBJECTS = \
"CMakeFiles/moukey_d.dir/src/device_display.cpp.o" \
"CMakeFiles/moukey_d.dir/src/server.cpp.o"

# External object files for target moukey_d
moukey_d_EXTERNAL_OBJECTS =

moukey_d: CMakeFiles/moukey_d.dir/src/device_display.cpp.o
moukey_d: CMakeFiles/moukey_d.dir/src/server.cpp.o
moukey_d: CMakeFiles/moukey_d.dir/build.make
moukey_d: libmoukey_lib.a
moukey_d: CMakeFiles/moukey_d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/german/moukey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable moukey_d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/moukey_d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/moukey_d.dir/build: moukey_d

.PHONY : CMakeFiles/moukey_d.dir/build

CMakeFiles/moukey_d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/moukey_d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/moukey_d.dir/clean

CMakeFiles/moukey_d.dir/depend:
	cd /home/german/moukey/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/german/moukey /home/german/moukey /home/german/moukey/cmake-build-debug /home/german/moukey/cmake-build-debug /home/german/moukey/cmake-build-debug/CMakeFiles/moukey_d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/moukey_d.dir/depend

