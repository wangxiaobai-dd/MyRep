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
include CMakeFiles/TestASyncRedis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestASyncRedis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestASyncRedis.dir/flags.make

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o: CMakeFiles/TestASyncRedis.dir/flags.make
CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o: ../TestASyncRedis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/RedisDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o -c /home/ubuntu/MyRep/RedisDir/TestASyncRedis.cpp

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/RedisDir/TestASyncRedis.cpp > CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.i

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/RedisDir/TestASyncRedis.cpp -o CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.s

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.requires:

.PHONY : CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.requires

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.provides: CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestASyncRedis.dir/build.make CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.provides.build
.PHONY : CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.provides

CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.provides.build: CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o


# Object files for target TestASyncRedis
TestASyncRedis_OBJECTS = \
"CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o"

# External object files for target TestASyncRedis
TestASyncRedis_EXTERNAL_OBJECTS =

TestASyncRedis: CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o
TestASyncRedis: CMakeFiles/TestASyncRedis.dir/build.make
TestASyncRedis: ../libEventLoop.a
TestASyncRedis: libredisProto.a
TestASyncRedis: CMakeFiles/TestASyncRedis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/RedisDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestASyncRedis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestASyncRedis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestASyncRedis.dir/build: TestASyncRedis

.PHONY : CMakeFiles/TestASyncRedis.dir/build

CMakeFiles/TestASyncRedis.dir/requires: CMakeFiles/TestASyncRedis.dir/TestASyncRedis.cpp.o.requires

.PHONY : CMakeFiles/TestASyncRedis.dir/requires

CMakeFiles/TestASyncRedis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestASyncRedis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestASyncRedis.dir/clean

CMakeFiles/TestASyncRedis.dir/depend:
	cd /home/ubuntu/MyRep/RedisDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/RedisDir /home/ubuntu/MyRep/RedisDir /home/ubuntu/MyRep/RedisDir/build /home/ubuntu/MyRep/RedisDir/build /home/ubuntu/MyRep/RedisDir/build/CMakeFiles/TestASyncRedis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestASyncRedis.dir/depend

