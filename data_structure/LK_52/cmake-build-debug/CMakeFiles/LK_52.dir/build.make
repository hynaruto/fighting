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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/LK_52

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/LK_52/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LK_52.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LK_52.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LK_52.dir/flags.make

CMakeFiles/LK_52.dir/main.cpp.o: CMakeFiles/LK_52.dir/flags.make
CMakeFiles/LK_52.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/LK_52/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LK_52.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LK_52.dir/main.cpp.o -c /Users/gibson/CLionProjects/LK_52/main.cpp

CMakeFiles/LK_52.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LK_52.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/LK_52/main.cpp > CMakeFiles/LK_52.dir/main.cpp.i

CMakeFiles/LK_52.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LK_52.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/LK_52/main.cpp -o CMakeFiles/LK_52.dir/main.cpp.s

# Object files for target LK_52
LK_52_OBJECTS = \
"CMakeFiles/LK_52.dir/main.cpp.o"

# External object files for target LK_52
LK_52_EXTERNAL_OBJECTS =

LK_52: CMakeFiles/LK_52.dir/main.cpp.o
LK_52: CMakeFiles/LK_52.dir/build.make
LK_52: CMakeFiles/LK_52.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/LK_52/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LK_52"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LK_52.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LK_52.dir/build: LK_52

.PHONY : CMakeFiles/LK_52.dir/build

CMakeFiles/LK_52.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LK_52.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LK_52.dir/clean

CMakeFiles/LK_52.dir/depend:
	cd /Users/gibson/CLionProjects/LK_52/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/LK_52 /Users/gibson/CLionProjects/LK_52 /Users/gibson/CLionProjects/LK_52/cmake-build-debug /Users/gibson/CLionProjects/LK_52/cmake-build-debug /Users/gibson/CLionProjects/LK_52/cmake-build-debug/CMakeFiles/LK_52.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LK_52.dir/depend

