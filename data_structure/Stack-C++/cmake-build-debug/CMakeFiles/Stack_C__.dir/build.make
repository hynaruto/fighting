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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/Stack-C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/Stack-C++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stack_C__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stack_C__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stack_C__.dir/flags.make

CMakeFiles/Stack_C__.dir/main.cpp.o: CMakeFiles/Stack_C__.dir/flags.make
CMakeFiles/Stack_C__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/Stack-C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stack_C__.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Stack_C__.dir/main.cpp.o -c /Users/gibson/CLionProjects/Stack-C++/main.cpp

CMakeFiles/Stack_C__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stack_C__.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/Stack-C++/main.cpp > CMakeFiles/Stack_C__.dir/main.cpp.i

CMakeFiles/Stack_C__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stack_C__.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/Stack-C++/main.cpp -o CMakeFiles/Stack_C__.dir/main.cpp.s

# Object files for target Stack_C__
Stack_C___OBJECTS = \
"CMakeFiles/Stack_C__.dir/main.cpp.o"

# External object files for target Stack_C__
Stack_C___EXTERNAL_OBJECTS =

Stack_C__: CMakeFiles/Stack_C__.dir/main.cpp.o
Stack_C__: CMakeFiles/Stack_C__.dir/build.make
Stack_C__: CMakeFiles/Stack_C__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/Stack-C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Stack_C__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stack_C__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stack_C__.dir/build: Stack_C__

.PHONY : CMakeFiles/Stack_C__.dir/build

CMakeFiles/Stack_C__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Stack_C__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Stack_C__.dir/clean

CMakeFiles/Stack_C__.dir/depend:
	cd /Users/gibson/CLionProjects/Stack-C++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/Stack-C++ /Users/gibson/CLionProjects/Stack-C++ /Users/gibson/CLionProjects/Stack-C++/cmake-build-debug /Users/gibson/CLionProjects/Stack-C++/cmake-build-debug /Users/gibson/CLionProjects/Stack-C++/cmake-build-debug/CMakeFiles/Stack_C__.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stack_C__.dir/depend
