# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/ubuntu/DownDir/cmake-3.19.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/ubuntu/DownDir/cmake-3.19.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/TestBcopy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestBcopy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestBcopy.dir/flags.make

CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o: CMakeFiles/TestBcopy.dir/flags.make
CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o: ../TestBcopy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o"
	/home/ubuntu/DownDir/cmake-3.19.1-Linux-x86_64/bin/cmake -E time /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o -c /home/ubuntu/MyRep/cpp/TestBcopy.cpp

CMakeFiles/TestBcopy.dir/TestBcopy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestBcopy.dir/TestBcopy.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/cpp/TestBcopy.cpp > CMakeFiles/TestBcopy.dir/TestBcopy.cpp.i

CMakeFiles/TestBcopy.dir/TestBcopy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestBcopy.dir/TestBcopy.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/cpp/TestBcopy.cpp -o CMakeFiles/TestBcopy.dir/TestBcopy.cpp.s

# Object files for target TestBcopy
TestBcopy_OBJECTS = \
"CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o"

# External object files for target TestBcopy
TestBcopy_EXTERNAL_OBJECTS =

TestBcopy: CMakeFiles/TestBcopy.dir/TestBcopy.cpp.o
TestBcopy: CMakeFiles/TestBcopy.dir/build.make
TestBcopy: CMakeFiles/TestBcopy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestBcopy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestBcopy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestBcopy.dir/build: TestBcopy

.PHONY : CMakeFiles/TestBcopy.dir/build

CMakeFiles/TestBcopy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestBcopy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestBcopy.dir/clean

CMakeFiles/TestBcopy.dir/depend:
	cd /home/ubuntu/MyRep/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build/CMakeFiles/TestBcopy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestBcopy.dir/depend

