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
include CMakeFiles/TestSignal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestSignal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestSignal.dir/flags.make

CMakeFiles/TestSignal.dir/TestSignal.cpp.o: CMakeFiles/TestSignal.dir/flags.make
CMakeFiles/TestSignal.dir/TestSignal.cpp.o: ../TestSignal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestSignal.dir/TestSignal.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestSignal.dir/TestSignal.cpp.o -c /home/ubuntu/MyRep/cpp/TestSignal.cpp

CMakeFiles/TestSignal.dir/TestSignal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSignal.dir/TestSignal.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/cpp/TestSignal.cpp > CMakeFiles/TestSignal.dir/TestSignal.cpp.i

CMakeFiles/TestSignal.dir/TestSignal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSignal.dir/TestSignal.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/cpp/TestSignal.cpp -o CMakeFiles/TestSignal.dir/TestSignal.cpp.s

# Object files for target TestSignal
TestSignal_OBJECTS = \
"CMakeFiles/TestSignal.dir/TestSignal.cpp.o"

# External object files for target TestSignal
TestSignal_EXTERNAL_OBJECTS =

TestSignal: CMakeFiles/TestSignal.dir/TestSignal.cpp.o
TestSignal: CMakeFiles/TestSignal.dir/build.make
TestSignal: CMakeFiles/TestSignal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSignal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSignal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestSignal.dir/build: TestSignal

.PHONY : CMakeFiles/TestSignal.dir/build

CMakeFiles/TestSignal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestSignal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestSignal.dir/clean

CMakeFiles/TestSignal.dir/depend:
	cd /home/ubuntu/MyRep/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build /home/ubuntu/MyRep/cpp/build/CMakeFiles/TestSignal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestSignal.dir/depend
