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
CMAKE_SOURCE_DIR = "/Users/gibson/CLionProjects/Leetcode(1)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Leetcode_1_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Leetcode_1_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Leetcode_1_.dir/flags.make

CMakeFiles/Leetcode_1_.dir/main.cpp.o: CMakeFiles/Leetcode_1_.dir/flags.make
CMakeFiles/Leetcode_1_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Leetcode_1_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Leetcode_1_.dir/main.cpp.o -c "/Users/gibson/CLionProjects/Leetcode(1)/main.cpp"

CMakeFiles/Leetcode_1_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Leetcode_1_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gibson/CLionProjects/Leetcode(1)/main.cpp" > CMakeFiles/Leetcode_1_.dir/main.cpp.i

CMakeFiles/Leetcode_1_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Leetcode_1_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gibson/CLionProjects/Leetcode(1)/main.cpp" -o CMakeFiles/Leetcode_1_.dir/main.cpp.s

# Object files for target Leetcode_1_
Leetcode_1__OBJECTS = \
"CMakeFiles/Leetcode_1_.dir/main.cpp.o"

# External object files for target Leetcode_1_
Leetcode_1__EXTERNAL_OBJECTS =

Leetcode_1_: CMakeFiles/Leetcode_1_.dir/main.cpp.o
Leetcode_1_: CMakeFiles/Leetcode_1_.dir/build.make
Leetcode_1_: CMakeFiles/Leetcode_1_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Leetcode_1_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Leetcode_1_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Leetcode_1_.dir/build: Leetcode_1_

.PHONY : CMakeFiles/Leetcode_1_.dir/build

CMakeFiles/Leetcode_1_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Leetcode_1_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Leetcode_1_.dir/clean

CMakeFiles/Leetcode_1_.dir/depend:
	cd "/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gibson/CLionProjects/Leetcode(1)" "/Users/gibson/CLionProjects/Leetcode(1)" "/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug" "/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug" "/Users/gibson/CLionProjects/Leetcode(1)/cmake-build-debug/CMakeFiles/Leetcode_1_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Leetcode_1_.dir/depend

