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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/SeqList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/SeqList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SeqList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SeqList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SeqList.dir/flags.make

CMakeFiles/SeqList.dir/main.c.o: CMakeFiles/SeqList.dir/flags.make
CMakeFiles/SeqList.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/SeqList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SeqList.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SeqList.dir/main.c.o   -c /Users/gibson/CLionProjects/SeqList/main.c

CMakeFiles/SeqList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SeqList.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gibson/CLionProjects/SeqList/main.c > CMakeFiles/SeqList.dir/main.c.i

CMakeFiles/SeqList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SeqList.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gibson/CLionProjects/SeqList/main.c -o CMakeFiles/SeqList.dir/main.c.s

CMakeFiles/SeqList.dir/SeqList.c.o: CMakeFiles/SeqList.dir/flags.make
CMakeFiles/SeqList.dir/SeqList.c.o: ../SeqList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/SeqList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SeqList.dir/SeqList.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SeqList.dir/SeqList.c.o   -c /Users/gibson/CLionProjects/SeqList/SeqList.c

CMakeFiles/SeqList.dir/SeqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SeqList.dir/SeqList.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gibson/CLionProjects/SeqList/SeqList.c > CMakeFiles/SeqList.dir/SeqList.c.i

CMakeFiles/SeqList.dir/SeqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SeqList.dir/SeqList.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gibson/CLionProjects/SeqList/SeqList.c -o CMakeFiles/SeqList.dir/SeqList.c.s

# Object files for target SeqList
SeqList_OBJECTS = \
"CMakeFiles/SeqList.dir/main.c.o" \
"CMakeFiles/SeqList.dir/SeqList.c.o"

# External object files for target SeqList
SeqList_EXTERNAL_OBJECTS =

SeqList: CMakeFiles/SeqList.dir/main.c.o
SeqList: CMakeFiles/SeqList.dir/SeqList.c.o
SeqList: CMakeFiles/SeqList.dir/build.make
SeqList: CMakeFiles/SeqList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/SeqList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable SeqList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SeqList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SeqList.dir/build: SeqList

.PHONY : CMakeFiles/SeqList.dir/build

CMakeFiles/SeqList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SeqList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SeqList.dir/clean

CMakeFiles/SeqList.dir/depend:
	cd /Users/gibson/CLionProjects/SeqList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/SeqList /Users/gibson/CLionProjects/SeqList /Users/gibson/CLionProjects/SeqList/cmake-build-debug /Users/gibson/CLionProjects/SeqList/cmake-build-debug /Users/gibson/CLionProjects/SeqList/cmake-build-debug/CMakeFiles/SeqList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SeqList.dir/depend

