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
CMAKE_SOURCE_DIR = "/Users/gibson/CLionProjects/LeetCode(4)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LeetCode_4_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeetCode_4_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeetCode_4_.dir/flags.make

CMakeFiles/LeetCode_4_.dir/main.cpp.o: CMakeFiles/LeetCode_4_.dir/flags.make
CMakeFiles/LeetCode_4_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeetCode_4_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCode_4_.dir/main.cpp.o -c "/Users/gibson/CLionProjects/LeetCode(4)/main.cpp"

CMakeFiles/LeetCode_4_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCode_4_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gibson/CLionProjects/LeetCode(4)/main.cpp" > CMakeFiles/LeetCode_4_.dir/main.cpp.i

CMakeFiles/LeetCode_4_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCode_4_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gibson/CLionProjects/LeetCode(4)/main.cpp" -o CMakeFiles/LeetCode_4_.dir/main.cpp.s

# Object files for target LeetCode_4_
LeetCode_4__OBJECTS = \
"CMakeFiles/LeetCode_4_.dir/main.cpp.o"

# External object files for target LeetCode_4_
LeetCode_4__EXTERNAL_OBJECTS =

LeetCode_4_: CMakeFiles/LeetCode_4_.dir/main.cpp.o
LeetCode_4_: CMakeFiles/LeetCode_4_.dir/build.make
LeetCode_4_: CMakeFiles/LeetCode_4_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LeetCode_4_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeetCode_4_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeetCode_4_.dir/build: LeetCode_4_

.PHONY : CMakeFiles/LeetCode_4_.dir/build

CMakeFiles/LeetCode_4_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeetCode_4_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeetCode_4_.dir/clean

CMakeFiles/LeetCode_4_.dir/depend:
	cd "/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gibson/CLionProjects/LeetCode(4)" "/Users/gibson/CLionProjects/LeetCode(4)" "/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug" "/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug" "/Users/gibson/CLionProjects/LeetCode(4)/cmake-build-debug/CMakeFiles/LeetCode_4_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LeetCode_4_.dir/depend

