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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/memcpy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/memcpy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/memcpy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memcpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memcpy.dir/flags.make

CMakeFiles/memcpy.dir/main.cpp.o: CMakeFiles/memcpy.dir/flags.make
CMakeFiles/memcpy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/memcpy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memcpy.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memcpy.dir/main.cpp.o -c /Users/gibson/CLionProjects/memcpy/main.cpp

CMakeFiles/memcpy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memcpy.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/memcpy/main.cpp > CMakeFiles/memcpy.dir/main.cpp.i

CMakeFiles/memcpy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memcpy.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/memcpy/main.cpp -o CMakeFiles/memcpy.dir/main.cpp.s

# Object files for target memcpy
memcpy_OBJECTS = \
"CMakeFiles/memcpy.dir/main.cpp.o"

# External object files for target memcpy
memcpy_EXTERNAL_OBJECTS =

memcpy: CMakeFiles/memcpy.dir/main.cpp.o
memcpy: CMakeFiles/memcpy.dir/build.make
memcpy: CMakeFiles/memcpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/memcpy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memcpy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memcpy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memcpy.dir/build: memcpy

.PHONY : CMakeFiles/memcpy.dir/build

CMakeFiles/memcpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memcpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memcpy.dir/clean

CMakeFiles/memcpy.dir/depend:
	cd /Users/gibson/CLionProjects/memcpy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/memcpy /Users/gibson/CLionProjects/memcpy /Users/gibson/CLionProjects/memcpy/cmake-build-debug /Users/gibson/CLionProjects/memcpy/cmake-build-debug /Users/gibson/CLionProjects/memcpy/cmake-build-debug/CMakeFiles/memcpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memcpy.dir/depend

