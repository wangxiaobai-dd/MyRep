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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/RedisDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/RedisDir/build

# Include any dependencies generated for this target.
include CMakeFiles/TestRedis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestRedis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestRedis.dir/flags.make

CMakeFiles/TestRedis.dir/TestRedis.cpp.o: CMakeFiles/TestRedis.dir/flags.make
CMakeFiles/TestRedis.dir/TestRedis.cpp.o: ../TestRedis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/RedisDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestRedis.dir/TestRedis.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestRedis.dir/TestRedis.cpp.o -c /home/ubuntu/MyRep/RedisDir/TestRedis.cpp

CMakeFiles/TestRedis.dir/TestRedis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestRedis.dir/TestRedis.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/RedisDir/TestRedis.cpp > CMakeFiles/TestRedis.dir/TestRedis.cpp.i

CMakeFiles/TestRedis.dir/TestRedis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestRedis.dir/TestRedis.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/RedisDir/TestRedis.cpp -o CMakeFiles/TestRedis.dir/TestRedis.cpp.s

CMakeFiles/TestRedis.dir/TestRedis.cpp.o.requires:

.PHONY : CMakeFiles/TestRedis.dir/TestRedis.cpp.o.requires

CMakeFiles/TestRedis.dir/TestRedis.cpp.o.provides: CMakeFiles/TestRedis.dir/TestRedis.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestRedis.dir/build.make CMakeFiles/TestRedis.dir/TestRedis.cpp.o.provides.build
.PHONY : CMakeFiles/TestRedis.dir/TestRedis.cpp.o.provides

CMakeFiles/TestRedis.dir/TestRedis.cpp.o.provides.build: CMakeFiles/TestRedis.dir/TestRedis.cpp.o


# Object files for target TestRedis
TestRedis_OBJECTS = \
"CMakeFiles/TestRedis.dir/TestRedis.cpp.o"

# External object files for target TestRedis
TestRedis_EXTERNAL_OBJECTS =

TestRedis: CMakeFiles/TestRedis.dir/TestRedis.cpp.o
TestRedis: CMakeFiles/TestRedis.dir/build.make
TestRedis: libredisProto.a
TestRedis: CMakeFiles/TestRedis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/RedisDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestRedis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestRedis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestRedis.dir/build: TestRedis

.PHONY : CMakeFiles/TestRedis.dir/build

CMakeFiles/TestRedis.dir/requires: CMakeFiles/TestRedis.dir/TestRedis.cpp.o.requires

.PHONY : CMakeFiles/TestRedis.dir/requires

CMakeFiles/TestRedis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestRedis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestRedis.dir/clean

CMakeFiles/TestRedis.dir/depend:
	cd /home/ubuntu/MyRep/RedisDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/RedisDir /home/ubuntu/MyRep/RedisDir /home/ubuntu/MyRep/RedisDir/build /home/ubuntu/MyRep/RedisDir/build /home/ubuntu/MyRep/RedisDir/build/CMakeFiles/TestRedis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestRedis.dir/depend

