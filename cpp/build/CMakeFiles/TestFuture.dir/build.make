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
include CMakeFiles/TestFuture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestFuture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestFuture.dir/flags.make

CMakeFiles/TestFuture.dir/TestFuture.cpp.o: CMakeFiles/TestFuture.dir/flags.make
CMakeFiles/TestFuture.dir/TestFuture.cpp.o: ../TestFuture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestFuture.dir/TestFuture.cpp.o"
	/home/ubuntu/DownDir/cmake-3.19.1-Linux-x86_64/bin/cmake -E time /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestFuture.dir/TestFuture.cpp.o -c /home/ubuntu/MyRep/cpp/TestFuture.cpp

CMakeFiles/TestFuture.dir/TestFuture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestFuture.dir/TestFuture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/cpp/TestFuture.cpp > CMakeFiles/TestFuture.dir/TestFuture.cpp.i

CMakeFiles/TestFuture.dir/TestFuture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestFuture.dir/TestFuture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/cpp/TestFuture.cpp -o CMakeFiles/TestFuture.dir/TestFuture.cpp.s

# Object files for target TestFuture
TestFuture_OBJECTS = \
"CMakeFiles/TestFuture.dir/TestFuture.cpp.o"

# External object files for target TestFuture
TestFuture_EXTERNAL_OBJECTS =

TestFuture: CMakeFiles/TestFuture.dir/TestFuture.cpp.o
TestFuture: CMakeFiles/TestFuture.dir/build.make
TestFuture: CMakeFiles/TestFuture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestFuture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestFuture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestFuture.dir/build: TestFuture

.PHONY : CMakeFiles/TestFuture.dir/build

CMakeFiles/TestFuture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestFuture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestFuture.dir/clean

CMakeFiles/TestFuture.dir/depend:
	cd /home/ubuntu/MyRep/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build/CMakeFiles/TestFuture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestFuture.dir/depend

