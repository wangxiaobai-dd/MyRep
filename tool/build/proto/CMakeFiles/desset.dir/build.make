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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/ToolDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/ToolDir/build

# Utility rule file for desset.

# Include the progress variables for this target.
include proto/CMakeFiles/desset.dir/progress.make

proto/CMakeFiles/desset:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "desset successful create"
	cd /home/ubuntu/MyRep/ToolDir/proto && protoc --cpp_out=/home/ubuntu/MyRep/ToolDir/proto --descriptor_set_out=des.set message.proto
	cd /home/ubuntu/MyRep/ToolDir/proto && mv des.set ../build/proto/
	cd /home/ubuntu/MyRep/ToolDir/proto && rm message.pb.h message.pb.cc

desset: proto/CMakeFiles/desset
desset: proto/CMakeFiles/desset.dir/build.make

.PHONY : desset

# Rule to build all files generated by this target.
proto/CMakeFiles/desset.dir/build: desset

.PHONY : proto/CMakeFiles/desset.dir/build

proto/CMakeFiles/desset.dir/clean:
	cd /home/ubuntu/MyRep/ToolDir/build/proto && $(CMAKE_COMMAND) -P CMakeFiles/desset.dir/cmake_clean.cmake
.PHONY : proto/CMakeFiles/desset.dir/clean

proto/CMakeFiles/desset.dir/depend:
	cd /home/ubuntu/MyRep/ToolDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/ToolDir /home/ubuntu/MyRep/ToolDir/proto /home/ubuntu/MyRep/ToolDir/build /home/ubuntu/MyRep/ToolDir/build/proto /home/ubuntu/MyRep/ToolDir/build/proto/CMakeFiles/desset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : proto/CMakeFiles/desset.dir/depend

