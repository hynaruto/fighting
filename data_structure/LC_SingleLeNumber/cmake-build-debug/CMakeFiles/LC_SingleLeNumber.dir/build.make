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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/LC_SingleLeNumber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LC_SingleLeNumber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LC_SingleLeNumber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LC_SingleLeNumber.dir/flags.make

CMakeFiles/LC_SingleLeNumber.dir/main.c.o: CMakeFiles/LC_SingleLeNumber.dir/flags.make
CMakeFiles/LC_SingleLeNumber.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LC_SingleLeNumber.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LC_SingleLeNumber.dir/main.c.o   -c /Users/gibson/CLionProjects/LC_SingleLeNumber/main.c

CMakeFiles/LC_SingleLeNumber.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LC_SingleLeNumber.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gibson/CLionProjects/LC_SingleLeNumber/main.c > CMakeFiles/LC_SingleLeNumber.dir/main.c.i

CMakeFiles/LC_SingleLeNumber.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LC_SingleLeNumber.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gibson/CLionProjects/LC_SingleLeNumber/main.c -o CMakeFiles/LC_SingleLeNumber.dir/main.c.s

# Object files for target LC_SingleLeNumber
LC_SingleLeNumber_OBJECTS = \
"CMakeFiles/LC_SingleLeNumber.dir/main.c.o"

# External object files for target LC_SingleLeNumber
LC_SingleLeNumber_EXTERNAL_OBJECTS =

LC_SingleLeNumber: CMakeFiles/LC_SingleLeNumber.dir/main.c.o
LC_SingleLeNumber: CMakeFiles/LC_SingleLeNumber.dir/build.make
LC_SingleLeNumber: CMakeFiles/LC_SingleLeNumber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LC_SingleLeNumber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LC_SingleLeNumber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LC_SingleLeNumber.dir/build: LC_SingleLeNumber

.PHONY : CMakeFiles/LC_SingleLeNumber.dir/build

CMakeFiles/LC_SingleLeNumber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LC_SingleLeNumber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LC_SingleLeNumber.dir/clean

CMakeFiles/LC_SingleLeNumber.dir/depend:
	cd /Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/LC_SingleLeNumber /Users/gibson/CLionProjects/LC_SingleLeNumber /Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug /Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug /Users/gibson/CLionProjects/LC_SingleLeNumber/cmake-build-debug/CMakeFiles/LC_SingleLeNumber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LC_SingleLeNumber.dir/depend

