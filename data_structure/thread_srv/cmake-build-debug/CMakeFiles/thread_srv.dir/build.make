# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/thread_srv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/thread_srv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/thread_srv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_srv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_srv.dir/flags.make

CMakeFiles/thread_srv.dir/main.cpp.o: CMakeFiles/thread_srv.dir/flags.make
CMakeFiles/thread_srv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/thread_srv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_srv.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thread_srv.dir/main.cpp.o -c /Users/gibson/CLionProjects/thread_srv/main.cpp

CMakeFiles/thread_srv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_srv.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/thread_srv/main.cpp > CMakeFiles/thread_srv.dir/main.cpp.i

CMakeFiles/thread_srv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_srv.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/thread_srv/main.cpp -o CMakeFiles/thread_srv.dir/main.cpp.s

# Object files for target thread_srv
thread_srv_OBJECTS = \
"CMakeFiles/thread_srv.dir/main.cpp.o"

# External object files for target thread_srv
thread_srv_EXTERNAL_OBJECTS =

thread_srv: CMakeFiles/thread_srv.dir/main.cpp.o
thread_srv: CMakeFiles/thread_srv.dir/build.make
thread_srv: CMakeFiles/thread_srv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/thread_srv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_srv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_srv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_srv.dir/build: thread_srv

.PHONY : CMakeFiles/thread_srv.dir/build

CMakeFiles/thread_srv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_srv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_srv.dir/clean

CMakeFiles/thread_srv.dir/depend:
	cd /Users/gibson/CLionProjects/thread_srv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/thread_srv /Users/gibson/CLionProjects/thread_srv /Users/gibson/CLionProjects/thread_srv/cmake-build-debug /Users/gibson/CLionProjects/thread_srv/cmake-build-debug /Users/gibson/CLionProjects/thread_srv/cmake-build-debug/CMakeFiles/thread_srv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread_srv.dir/depend

