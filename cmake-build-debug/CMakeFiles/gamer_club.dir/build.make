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
include CMakeFiles/gamer_club.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gamer_club.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gamer_club.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gamer_club.dir/flags.make

CMakeFiles/gamer_club.dir/main.cpp.o: CMakeFiles/gamer_club.dir/flags.make
CMakeFiles/gamer_club.dir/main.cpp.o: /home/vitalii/Documents/Programming/cpp/Game_club/main.cpp
CMakeFiles/gamer_club.dir/main.cpp.o: CMakeFiles/gamer_club.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gamer_club.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamer_club.dir/main.cpp.o -MF CMakeFiles/gamer_club.dir/main.cpp.o.d -o CMakeFiles/gamer_club.dir/main.cpp.o -c /home/vitalii/Documents/Programming/cpp/Game_club/main.cpp

CMakeFiles/gamer_club.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gamer_club.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vitalii/Documents/Programming/cpp/Game_club/main.cpp > CMakeFiles/gamer_club.dir/main.cpp.i

CMakeFiles/gamer_club.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gamer_club.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vitalii/Documents/Programming/cpp/Game_club/main.cpp -o CMakeFiles/gamer_club.dir/main.cpp.s

# Object files for target gamer_club
gamer_club_OBJECTS = \
"CMakeFiles/gamer_club.dir/main.cpp.o"

# External object files for target gamer_club
gamer_club_EXTERNAL_OBJECTS =

gamer_club: CMakeFiles/gamer_club.dir/main.cpp.o
gamer_club: CMakeFiles/gamer_club.dir/build.make
gamer_club: libsource_lib.a
gamer_club: CMakeFiles/gamer_club.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gamer_club"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gamer_club.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gamer_club.dir/build: gamer_club
.PHONY : CMakeFiles/gamer_club.dir/build

CMakeFiles/gamer_club.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gamer_club.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gamer_club.dir/clean

CMakeFiles/gamer_club.dir/depend:
	cd /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vitalii/Documents/Programming/cpp/Game_club /home/vitalii/Documents/Programming/cpp/Game_club /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug /home/vitalii/Documents/Programming/cpp/Game_club/cmake-build-debug/CMakeFiles/gamer_club.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/gamer_club.dir/depend

