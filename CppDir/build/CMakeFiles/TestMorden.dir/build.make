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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/CppDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/CppDir/build

# Include any dependencies generated for this target.
include CMakeFiles/TestMorden.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestMorden.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestMorden.dir/flags.make

CMakeFiles/TestMorden.dir/TestMorden.cpp.o: CMakeFiles/TestMorden.dir/flags.make
CMakeFiles/TestMorden.dir/TestMorden.cpp.o: ../TestMorden.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestMorden.dir/TestMorden.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestMorden.dir/TestMorden.cpp.o -c /home/ubuntu/MyRep/CppDir/TestMorden.cpp

CMakeFiles/TestMorden.dir/TestMorden.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestMorden.dir/TestMorden.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/CppDir/TestMorden.cpp > CMakeFiles/TestMorden.dir/TestMorden.cpp.i

CMakeFiles/TestMorden.dir/TestMorden.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestMorden.dir/TestMorden.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/CppDir/TestMorden.cpp -o CMakeFiles/TestMorden.dir/TestMorden.cpp.s

CMakeFiles/TestMorden.dir/TestMorden.cpp.o.requires:

.PHONY : CMakeFiles/TestMorden.dir/TestMorden.cpp.o.requires

CMakeFiles/TestMorden.dir/TestMorden.cpp.o.provides: CMakeFiles/TestMorden.dir/TestMorden.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestMorden.dir/build.make CMakeFiles/TestMorden.dir/TestMorden.cpp.o.provides.build
.PHONY : CMakeFiles/TestMorden.dir/TestMorden.cpp.o.provides

CMakeFiles/TestMorden.dir/TestMorden.cpp.o.provides.build: CMakeFiles/TestMorden.dir/TestMorden.cpp.o


# Object files for target TestMorden
TestMorden_OBJECTS = \
"CMakeFiles/TestMorden.dir/TestMorden.cpp.o"

# External object files for target TestMorden
TestMorden_EXTERNAL_OBJECTS =

TestMorden: CMakeFiles/TestMorden.dir/TestMorden.cpp.o
TestMorden: CMakeFiles/TestMorden.dir/build.make
TestMorden: CMakeFiles/TestMorden.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestMorden"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestMorden.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestMorden.dir/build: TestMorden

.PHONY : CMakeFiles/TestMorden.dir/build

CMakeFiles/TestMorden.dir/requires: CMakeFiles/TestMorden.dir/TestMorden.cpp.o.requires

.PHONY : CMakeFiles/TestMorden.dir/requires

CMakeFiles/TestMorden.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestMorden.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestMorden.dir/clean

CMakeFiles/TestMorden.dir/depend:
	cd /home/ubuntu/MyRep/CppDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build/CMakeFiles/TestMorden.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestMorden.dir/depend
