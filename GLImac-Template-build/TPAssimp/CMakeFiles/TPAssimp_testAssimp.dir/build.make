# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/erwann/Documents/OpenGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erwann/Documents/OpenGL/GLImac-Template-build

# Include any dependencies generated for this target.
include TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/depend.make

# Include the progress variables for this target.
include TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/progress.make

# Include the compile flags for this target's objects.
include TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/flags.make

TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o: TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/flags.make
TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o: /home/erwann/Documents/OpenGL/GLImac-Template/TPAssimp/testAssimp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erwann/Documents/OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o -c /home/erwann/Documents/OpenGL/GLImac-Template/TPAssimp/testAssimp.cpp

TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.i"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erwann/Documents/OpenGL/GLImac-Template/TPAssimp/testAssimp.cpp > CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.i

TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.s"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erwann/Documents/OpenGL/GLImac-Template/TPAssimp/testAssimp.cpp -o CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.s

# Object files for target TPAssimp_testAssimp
TPAssimp_testAssimp_OBJECTS = \
"CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o"

# External object files for target TPAssimp_testAssimp
TPAssimp_testAssimp_EXTERNAL_OBJECTS =

TPAssimp/TPAssimp_testAssimp: TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/testAssimp.cpp.o
TPAssimp/TPAssimp_testAssimp: TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/build.make
TPAssimp/TPAssimp_testAssimp: glimac/libglimac.a
TPAssimp/TPAssimp_testAssimp: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TPAssimp/TPAssimp_testAssimp: /usr/lib/x86_64-linux-gnu/libSDL.so
TPAssimp/TPAssimp_testAssimp: /usr/lib/x86_64-linux-gnu/libGL.so.1
TPAssimp/TPAssimp_testAssimp: /usr/lib/x86_64-linux-gnu/libGLEW.so
TPAssimp/TPAssimp_testAssimp: TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erwann/Documents/OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TPAssimp_testAssimp"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TPAssimp_testAssimp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/build: TPAssimp/TPAssimp_testAssimp

.PHONY : TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/build

TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/clean:
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp && $(CMAKE_COMMAND) -P CMakeFiles/TPAssimp_testAssimp.dir/cmake_clean.cmake
.PHONY : TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/clean

TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/depend:
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erwann/Documents/OpenGL/GLImac-Template /home/erwann/Documents/OpenGL/GLImac-Template/TPAssimp /home/erwann/Documents/OpenGL/GLImac-Template-build /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp /home/erwann/Documents/OpenGL/GLImac-Template-build/TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TPAssimp/CMakeFiles/TPAssimp_testAssimp.dir/depend

