# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/vitalii/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/vitalii/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vitalii/Documents/Programming/cpp/Game_club

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/try_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/try_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/try_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/try_test.dir/flags.make

test/CMakeFiles/try_test.dir/try_test.cpp.o: test/CMakeFiles/try_test.dir/flags.make
test/CMakeFiles/try_test.dir/try_test.cpp.o: /home/vitalii/Documents/Programming/cpp/Game_club/test/try_test.cpp
test/CMakeFiles/try_test.dir/try_test.cpp.o: test/CMakeFiles/try_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/try_test.dir/try_test.cpp.o"
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/try_test.dir/try_test.cpp.o -MF CMakeFiles/try_test.dir/try_test.cpp.o.d -o CMakeFiles/try_test.dir/try_test.cpp.o -c /home/vitalii/Documents/Programming/cpp/Game_club/test/try_test.cpp

test/CMakeFiles/try_test.dir/try_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/try_test.dir/try_test.cpp.i"
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vitalii/Documents/Programming/cpp/Game_club/test/try_test.cpp > CMakeFiles/try_test.dir/try_test.cpp.i

test/CMakeFiles/try_test.dir/try_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/try_test.dir/try_test.cpp.s"
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vitalii/Documents/Programming/cpp/Game_club/test/try_test.cpp -o CMakeFiles/try_test.dir/try_test.cpp.s

# Object files for target try_test
try_test_OBJECTS = \
"CMakeFiles/try_test.dir/try_test.cpp.o"

# External object files for target try_test
try_test_EXTERNAL_OBJECTS =

test/try_test: test/CMakeFiles/try_test.dir/try_test.cpp.o
test/try_test: test/CMakeFiles/try_test.dir/build.make
test/try_test: test/CMakeFiles/try_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable try_test"
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/try_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/try_test.dir/build: test/try_test
.PHONY : test/CMakeFiles/try_test.dir/build

test/CMakeFiles/try_test.dir/clean:
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/try_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/try_test.dir/clean

test/CMakeFiles/try_test.dir/depend:
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vitalii/Documents/Programming/cpp/Game_club /home/vitalii/Documents/Programming/cpp/Game_club/test /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/test/CMakeFiles/try_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/try_test.dir/depend

