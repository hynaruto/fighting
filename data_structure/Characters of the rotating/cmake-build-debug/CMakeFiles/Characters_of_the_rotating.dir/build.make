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
CMAKE_SOURCE_DIR = "/Users/gibson/CLionProjects/Characters of the rotating"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Characters_of_the_rotating.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Characters_of_the_rotating.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Characters_of_the_rotating.dir/flags.make

CMakeFiles/Characters_of_the_rotating.dir/main.c.o: CMakeFiles/Characters_of_the_rotating.dir/flags.make
CMakeFiles/Characters_of_the_rotating.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Characters_of_the_rotating.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Characters_of_the_rotating.dir/main.c.o   -c "/Users/gibson/CLionProjects/Characters of the rotating/main.c"

CMakeFiles/Characters_of_the_rotating.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Characters_of_the_rotating.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gibson/CLionProjects/Characters of the rotating/main.c" > CMakeFiles/Characters_of_the_rotating.dir/main.c.i

CMakeFiles/Characters_of_the_rotating.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Characters_of_the_rotating.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gibson/CLionProjects/Characters of the rotating/main.c" -o CMakeFiles/Characters_of_the_rotating.dir/main.c.s

# Object files for target Characters_of_the_rotating
Characters_of_the_rotating_OBJECTS = \
"CMakeFiles/Characters_of_the_rotating.dir/main.c.o"

# External object files for target Characters_of_the_rotating
Characters_of_the_rotating_EXTERNAL_OBJECTS =

Characters_of_the_rotating: CMakeFiles/Characters_of_the_rotating.dir/main.c.o
Characters_of_the_rotating: CMakeFiles/Characters_of_the_rotating.dir/build.make
Characters_of_the_rotating: CMakeFiles/Characters_of_the_rotating.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Characters_of_the_rotating"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Characters_of_the_rotating.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Characters_of_the_rotating.dir/build: Characters_of_the_rotating

.PHONY : CMakeFiles/Characters_of_the_rotating.dir/build

CMakeFiles/Characters_of_the_rotating.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Characters_of_the_rotating.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Characters_of_the_rotating.dir/clean

CMakeFiles/Characters_of_the_rotating.dir/depend:
	cd "/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gibson/CLionProjects/Characters of the rotating" "/Users/gibson/CLionProjects/Characters of the rotating" "/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug" "/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug" "/Users/gibson/CLionProjects/Characters of the rotating/cmake-build-debug/CMakeFiles/Characters_of_the_rotating.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Characters_of_the_rotating.dir/depend

