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
include CMakeFiles/TestIndexSeq.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestIndexSeq.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestIndexSeq.dir/flags.make

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o: CMakeFiles/TestIndexSeq.dir/flags.make
CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o: ../TestIndexSeq.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o -c /home/ubuntu/MyRep/CppDir/TestIndexSeq.cpp

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/CppDir/TestIndexSeq.cpp > CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.i

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/CppDir/TestIndexSeq.cpp -o CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.s

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.requires:

.PHONY : CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.requires

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.provides: CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestIndexSeq.dir/build.make CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.provides.build
.PHONY : CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.provides

CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.provides.build: CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o


# Object files for target TestIndexSeq
TestIndexSeq_OBJECTS = \
"CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o"

# External object files for target TestIndexSeq
TestIndexSeq_EXTERNAL_OBJECTS =

TestIndexSeq: CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o
TestIndexSeq: CMakeFiles/TestIndexSeq.dir/build.make
TestIndexSeq: CMakeFiles/TestIndexSeq.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestIndexSeq"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestIndexSeq.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestIndexSeq.dir/build: TestIndexSeq

.PHONY : CMakeFiles/TestIndexSeq.dir/build

CMakeFiles/TestIndexSeq.dir/requires: CMakeFiles/TestIndexSeq.dir/TestIndexSeq.cpp.o.requires

.PHONY : CMakeFiles/TestIndexSeq.dir/requires

CMakeFiles/TestIndexSeq.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestIndexSeq.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestIndexSeq.dir/clean

CMakeFiles/TestIndexSeq.dir/depend:
	cd /home/ubuntu/MyRep/CppDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build/CMakeFiles/TestIndexSeq.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestIndexSeq.dir/depend

