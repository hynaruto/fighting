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
CMAKE_SOURCE_DIR = /Users/gibson/CLionProjects/chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gibson/CLionProjects/chess/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/main.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/chess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/main.cpp.o -c /Users/gibson/CLionProjects/chess/main.cpp

CMakeFiles/chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/chess/main.cpp > CMakeFiles/chess.dir/main.cpp.i

CMakeFiles/chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/chess/main.cpp -o CMakeFiles/chess.dir/main.cpp.s

CMakeFiles/chess.dir/chess.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/chess.cpp.o: ../chess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gibson/CLionProjects/chess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/chess.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/chess.cpp.o -c /Users/gibson/CLionProjects/chess/chess.cpp

CMakeFiles/chess.dir/chess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/chess.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gibson/CLionProjects/chess/chess.cpp > CMakeFiles/chess.dir/chess.cpp.i

CMakeFiles/chess.dir/chess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/chess.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gibson/CLionProjects/chess/chess.cpp -o CMakeFiles/chess.dir/chess.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/main.cpp.o" \
"CMakeFiles/chess.dir/chess.cpp.o"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess: CMakeFiles/chess.dir/main.cpp.o
chess: CMakeFiles/chess.dir/chess.cpp.o
chess: CMakeFiles/chess.dir/build.make
chess: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gibson/CLionProjects/chess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess

.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	cd /Users/gibson/CLionProjects/chess/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gibson/CLionProjects/chess /Users/gibson/CLionProjects/chess /Users/gibson/CLionProjects/chess/cmake-build-debug /Users/gibson/CLionProjects/chess/cmake-build-debug /Users/gibson/CLionProjects/chess/cmake-build-debug/CMakeFiles/chess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend

