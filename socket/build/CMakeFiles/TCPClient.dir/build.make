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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/SocketDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/SocketDir/build

# Include any dependencies generated for this target.
include CMakeFiles/TCPClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCPClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCPClient.dir/flags.make

CMakeFiles/TCPClient.dir/TCPClient.cpp.o: CMakeFiles/TCPClient.dir/flags.make
CMakeFiles/TCPClient.dir/TCPClient.cpp.o: ../TCPClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/SocketDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TCPClient.dir/TCPClient.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPClient.dir/TCPClient.cpp.o -c /home/ubuntu/MyRep/SocketDir/TCPClient.cpp

CMakeFiles/TCPClient.dir/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPClient.dir/TCPClient.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/SocketDir/TCPClient.cpp > CMakeFiles/TCPClient.dir/TCPClient.cpp.i

CMakeFiles/TCPClient.dir/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPClient.dir/TCPClient.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/SocketDir/TCPClient.cpp -o CMakeFiles/TCPClient.dir/TCPClient.cpp.s

CMakeFiles/TCPClient.dir/TCPClient.cpp.o.requires:

.PHONY : CMakeFiles/TCPClient.dir/TCPClient.cpp.o.requires

CMakeFiles/TCPClient.dir/TCPClient.cpp.o.provides: CMakeFiles/TCPClient.dir/TCPClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/TCPClient.dir/build.make CMakeFiles/TCPClient.dir/TCPClient.cpp.o.provides.build
.PHONY : CMakeFiles/TCPClient.dir/TCPClient.cpp.o.provides

CMakeFiles/TCPClient.dir/TCPClient.cpp.o.provides.build: CMakeFiles/TCPClient.dir/TCPClient.cpp.o


# Object files for target TCPClient
TCPClient_OBJECTS = \
"CMakeFiles/TCPClient.dir/TCPClient.cpp.o"

# External object files for target TCPClient
TCPClient_EXTERNAL_OBJECTS =

TCPClient: CMakeFiles/TCPClient.dir/TCPClient.cpp.o
TCPClient: CMakeFiles/TCPClient.dir/build.make
TCPClient: CMakeFiles/TCPClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/SocketDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TCPClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCPClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCPClient.dir/build: TCPClient

.PHONY : CMakeFiles/TCPClient.dir/build

CMakeFiles/TCPClient.dir/requires: CMakeFiles/TCPClient.dir/TCPClient.cpp.o.requires

.PHONY : CMakeFiles/TCPClient.dir/requires

CMakeFiles/TCPClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCPClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCPClient.dir/clean

CMakeFiles/TCPClient.dir/depend:
	cd /home/ubuntu/MyRep/SocketDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/SocketDir /home/ubuntu/MyRep/SocketDir /home/ubuntu/MyRep/SocketDir/build /home/ubuntu/MyRep/SocketDir/build /home/ubuntu/MyRep/SocketDir/build/CMakeFiles/TCPClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCPClient.dir/depend
