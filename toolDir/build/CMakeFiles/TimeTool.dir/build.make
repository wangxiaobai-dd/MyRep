# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/toolDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/toolDir/build

# Include any dependencies generated for this target.
include CMakeFiles/TimeTool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TimeTool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TimeTool.dir/flags.make

CMakeFiles/TimeTool.dir/TimeTool.cpp.o: CMakeFiles/TimeTool.dir/flags.make
CMakeFiles/TimeTool.dir/TimeTool.cpp.o: ../TimeTool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/toolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TimeTool.dir/TimeTool.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TimeTool.dir/TimeTool.cpp.o -c /home/ubuntu/MyRep/toolDir/TimeTool.cpp

CMakeFiles/TimeTool.dir/TimeTool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TimeTool.dir/TimeTool.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/toolDir/TimeTool.cpp > CMakeFiles/TimeTool.dir/TimeTool.cpp.i

CMakeFiles/TimeTool.dir/TimeTool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TimeTool.dir/TimeTool.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/toolDir/TimeTool.cpp -o CMakeFiles/TimeTool.dir/TimeTool.cpp.s

CMakeFiles/TimeTool.dir/TimeTool.cpp.o.requires:

.PHONY : CMakeFiles/TimeTool.dir/TimeTool.cpp.o.requires

CMakeFiles/TimeTool.dir/TimeTool.cpp.o.provides: CMakeFiles/TimeTool.dir/TimeTool.cpp.o.requires
	$(MAKE) -f CMakeFiles/TimeTool.dir/build.make CMakeFiles/TimeTool.dir/TimeTool.cpp.o.provides.build
.PHONY : CMakeFiles/TimeTool.dir/TimeTool.cpp.o.provides

CMakeFiles/TimeTool.dir/TimeTool.cpp.o.provides.build: CMakeFiles/TimeTool.dir/TimeTool.cpp.o


# Object files for target TimeTool
TimeTool_OBJECTS = \
"CMakeFiles/TimeTool.dir/TimeTool.cpp.o"

# External object files for target TimeTool
TimeTool_EXTERNAL_OBJECTS =

TimeTool: CMakeFiles/TimeTool.dir/TimeTool.cpp.o
TimeTool: CMakeFiles/TimeTool.dir/build.make
TimeTool: CMakeFiles/TimeTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/toolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TimeTool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TimeTool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TimeTool.dir/build: TimeTool

.PHONY : CMakeFiles/TimeTool.dir/build

CMakeFiles/TimeTool.dir/requires: CMakeFiles/TimeTool.dir/TimeTool.cpp.o.requires

.PHONY : CMakeFiles/TimeTool.dir/requires

CMakeFiles/TimeTool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TimeTool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TimeTool.dir/clean

CMakeFiles/TimeTool.dir/depend:
	cd /home/ubuntu/MyRep/toolDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/toolDir /home/ubuntu/MyRep/toolDir /home/ubuntu/MyRep/toolDir/build /home/ubuntu/MyRep/toolDir/build /home/ubuntu/MyRep/toolDir/build/CMakeFiles/TimeTool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TimeTool.dir/depend

