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
include CMakeFiles/TestEnumClass.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestEnumClass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestEnumClass.dir/flags.make

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o: CMakeFiles/TestEnumClass.dir/flags.make
CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o: ../TestEnumClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o -c /home/ubuntu/MyRep/CppDir/TestEnumClass.cpp

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/CppDir/TestEnumClass.cpp > CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.i

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/CppDir/TestEnumClass.cpp -o CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.s

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.requires:

.PHONY : CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.requires

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.provides: CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestEnumClass.dir/build.make CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.provides.build
.PHONY : CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.provides

CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.provides.build: CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o


# Object files for target TestEnumClass
TestEnumClass_OBJECTS = \
"CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o"

# External object files for target TestEnumClass
TestEnumClass_EXTERNAL_OBJECTS =

TestEnumClass: CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o
TestEnumClass: CMakeFiles/TestEnumClass.dir/build.make
TestEnumClass: CMakeFiles/TestEnumClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/CppDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestEnumClass"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestEnumClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestEnumClass.dir/build: TestEnumClass

.PHONY : CMakeFiles/TestEnumClass.dir/build

CMakeFiles/TestEnumClass.dir/requires: CMakeFiles/TestEnumClass.dir/TestEnumClass.cpp.o.requires

.PHONY : CMakeFiles/TestEnumClass.dir/requires

CMakeFiles/TestEnumClass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestEnumClass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestEnumClass.dir/clean

CMakeFiles/TestEnumClass.dir/depend:
	cd /home/ubuntu/MyRep/CppDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build /home/ubuntu/MyRep/CppDir/build/CMakeFiles/TestEnumClass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestEnumClass.dir/depend

