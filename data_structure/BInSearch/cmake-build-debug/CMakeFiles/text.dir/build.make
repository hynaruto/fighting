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
CMAKE_SOURCE_DIR = /Users/gibson/coding/data_structure/data_structure/BinSearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/text.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/text.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text.dir/flags.make

CMakeFiles/text.dir/main.cpp.o: CMakeFiles/text.dir/flags.make
CMakeFiles/text.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/text.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/text.dir/main.cpp.o -c /Users/gibson/coding/data_structure/data_structure/BinSearch/main.cpp

CMakeFiles/text.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/text.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/coding/data_structure/data_structure/BinSearch/main.cpp > CMakeFiles/text.dir/main.cpp.i

CMakeFiles/text.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/text.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/coding/data_structure/data_structure/BinSearch/main.cpp -o CMakeFiles/text.dir/main.cpp.s

# Object files for target text
text_OBJECTS = \
"CMakeFiles/text.dir/main.cpp.o"

# External object files for target text
text_EXTERNAL_OBJECTS =

text: CMakeFiles/text.dir/main.cpp.o
text: CMakeFiles/text.dir/build.make
text: CMakeFiles/text.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable text"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/text.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text.dir/build: text

.PHONY : CMakeFiles/text.dir/build

CMakeFiles/text.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/text.dir/cmake_clean.cmake
.PHONY : CMakeFiles/text.dir/clean

CMakeFiles/text.dir/depend:
	cd /Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/coding/data_structure/data_structure/BinSearch /Users/gibson/coding/data_structure/data_structure/BinSearch /Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug /Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug /Users/gibson/coding/data_structure/data_structure/BinSearch/cmake-build-debug/CMakeFiles/text.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/text.dir/depend

