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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/memmove

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/memmove/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/memmove.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memmove.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memmove.dir/flags.make

CMakeFiles/memmove.dir/main.cpp.o: CMakeFiles/memmove.dir/flags.make
CMakeFiles/memmove.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/memmove/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memmove.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memmove.dir/main.cpp.o -c /Users/gibson/CLionProjects/memmove/main.cpp

CMakeFiles/memmove.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memmove.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/memmove/main.cpp > CMakeFiles/memmove.dir/main.cpp.i

CMakeFiles/memmove.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memmove.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/memmove/main.cpp -o CMakeFiles/memmove.dir/main.cpp.s

# Object files for target memmove
memmove_OBJECTS = \
"CMakeFiles/memmove.dir/main.cpp.o"

# External object files for target memmove
memmove_EXTERNAL_OBJECTS =

memmove: CMakeFiles/memmove.dir/main.cpp.o
memmove: CMakeFiles/memmove.dir/build.make
memmove: CMakeFiles/memmove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/memmove/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memmove"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memmove.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memmove.dir/build: memmove

.PHONY : CMakeFiles/memmove.dir/build

CMakeFiles/memmove.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memmove.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memmove.dir/clean

CMakeFiles/memmove.dir/depend:
	cd /Users/gibson/CLionProjects/memmove/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/memmove /Users/gibson/CLionProjects/memmove /Users/gibson/CLionProjects/memmove/cmake-build-debug /Users/gibson/CLionProjects/memmove/cmake-build-debug /Users/gibson/CLionProjects/memmove/cmake-build-debug/CMakeFiles/memmove.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memmove.dir/depend
