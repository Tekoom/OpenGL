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
include TP3/CMakeFiles/TP3_multi_texturing.dir/depend.make

# Include the progress variables for this target.
include TP3/CMakeFiles/TP3_multi_texturing.dir/progress.make

# Include the compile flags for this target's objects.
include TP3/CMakeFiles/TP3_multi_texturing.dir/flags.make

TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o: TP3/CMakeFiles/TP3_multi_texturing.dir/flags.make
TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o: /home/erwann/Documents/OpenGL/GLImac-Template/TP3/multi_texturing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erwann/Documents/OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o -c /home/erwann/Documents/OpenGL/GLImac-Template/TP3/multi_texturing.cpp

TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.i"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erwann/Documents/OpenGL/GLImac-Template/TP3/multi_texturing.cpp > CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.i

TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.s"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erwann/Documents/OpenGL/GLImac-Template/TP3/multi_texturing.cpp -o CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.s

# Object files for target TP3_multi_texturing
TP3_multi_texturing_OBJECTS = \
"CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o"

# External object files for target TP3_multi_texturing
TP3_multi_texturing_EXTERNAL_OBJECTS =

TP3/TP3_multi_texturing: TP3/CMakeFiles/TP3_multi_texturing.dir/multi_texturing.cpp.o
TP3/TP3_multi_texturing: TP3/CMakeFiles/TP3_multi_texturing.dir/build.make
TP3/TP3_multi_texturing: glimac/libglimac.a
TP3/TP3_multi_texturing: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP3/TP3_multi_texturing: /usr/lib/x86_64-linux-gnu/libSDL.so
TP3/TP3_multi_texturing: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP3/TP3_multi_texturing: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP3/TP3_multi_texturing: TP3/CMakeFiles/TP3_multi_texturing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erwann/Documents/OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP3_multi_texturing"
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP3_multi_texturing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP3/CMakeFiles/TP3_multi_texturing.dir/build: TP3/TP3_multi_texturing

.PHONY : TP3/CMakeFiles/TP3_multi_texturing.dir/build

TP3/CMakeFiles/TP3_multi_texturing.dir/clean:
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -P CMakeFiles/TP3_multi_texturing.dir/cmake_clean.cmake
.PHONY : TP3/CMakeFiles/TP3_multi_texturing.dir/clean

TP3/CMakeFiles/TP3_multi_texturing.dir/depend:
	cd /home/erwann/Documents/OpenGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erwann/Documents/OpenGL/GLImac-Template /home/erwann/Documents/OpenGL/GLImac-Template/TP3 /home/erwann/Documents/OpenGL/GLImac-Template-build /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3 /home/erwann/Documents/OpenGL/GLImac-Template-build/TP3/CMakeFiles/TP3_multi_texturing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP3/CMakeFiles/TP3_multi_texturing.dir/depend

