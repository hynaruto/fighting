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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/Heap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/Heap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Heap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Heap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Heap.dir/flags.make

CMakeFiles/Heap.dir/main.c.o: CMakeFiles/Heap.dir/flags.make
CMakeFiles/Heap.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/Heap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Heap.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Heap.dir/main.c.o   -c /Users/gibson/CLionProjects/Heap/main.c

CMakeFiles/Heap.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Heap.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gibson/CLionProjects/Heap/main.c > CMakeFiles/Heap.dir/main.c.i

CMakeFiles/Heap.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Heap.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gibson/CLionProjects/Heap/main.c -o CMakeFiles/Heap.dir/main.c.s

CMakeFiles/Heap.dir/Heap.c.o: CMakeFiles/Heap.dir/flags.make
CMakeFiles/Heap.dir/Heap.c.o: ../Heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/Heap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Heap.dir/Heap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Heap.dir/Heap.c.o   -c /Users/gibson/CLionProjects/Heap/Heap.c

CMakeFiles/Heap.dir/Heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Heap.dir/Heap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gibson/CLionProjects/Heap/Heap.c > CMakeFiles/Heap.dir/Heap.c.i

CMakeFiles/Heap.dir/Heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Heap.dir/Heap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gibson/CLionProjects/Heap/Heap.c -o CMakeFiles/Heap.dir/Heap.c.s

# Object files for target Heap
Heap_OBJECTS = \
"CMakeFiles/Heap.dir/main.c.o" \
"CMakeFiles/Heap.dir/Heap.c.o"

# External object files for target Heap
Heap_EXTERNAL_OBJECTS =

Heap: CMakeFiles/Heap.dir/main.c.o
Heap: CMakeFiles/Heap.dir/Heap.c.o
Heap: CMakeFiles/Heap.dir/build.make
Heap: CMakeFiles/Heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/Heap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Heap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Heap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Heap.dir/build: Heap

.PHONY : CMakeFiles/Heap.dir/build

CMakeFiles/Heap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Heap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Heap.dir/clean

CMakeFiles/Heap.dir/depend:
	cd /Users/gibson/CLionProjects/Heap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/Heap /Users/gibson/CLionProjects/Heap /Users/gibson/CLionProjects/Heap/cmake-build-debug /Users/gibson/CLionProjects/Heap/cmake-build-debug /Users/gibson/CLionProjects/Heap/cmake-build-debug/CMakeFiles/Heap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Heap.dir/depend

