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

# Include any dependencies generated for this target.
include CMakeFiles/PBTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PBTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PBTest.dir/flags.make

message.pb.cc: ../proto/message.proto
message.pb.cc: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on proto/message.proto"
	/usr/local/bin/protoc --cpp_out=/home/ubuntu/MyRep/ToolDir/build -I /home/ubuntu/MyRep/ToolDir/proto /home/ubuntu/MyRep/ToolDir/proto/message.proto

message.pb.h: message.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate message.pb.h

CMakeFiles/PBTest.dir/ProtoTest.cpp.o: CMakeFiles/PBTest.dir/flags.make
CMakeFiles/PBTest.dir/ProtoTest.cpp.o: ../ProtoTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PBTest.dir/ProtoTest.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PBTest.dir/ProtoTest.cpp.o -c /home/ubuntu/MyRep/ToolDir/ProtoTest.cpp

CMakeFiles/PBTest.dir/ProtoTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PBTest.dir/ProtoTest.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/ToolDir/ProtoTest.cpp > CMakeFiles/PBTest.dir/ProtoTest.cpp.i

CMakeFiles/PBTest.dir/ProtoTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PBTest.dir/ProtoTest.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/ToolDir/ProtoTest.cpp -o CMakeFiles/PBTest.dir/ProtoTest.cpp.s

CMakeFiles/PBTest.dir/ProtoTest.cpp.o.requires:

.PHONY : CMakeFiles/PBTest.dir/ProtoTest.cpp.o.requires

CMakeFiles/PBTest.dir/ProtoTest.cpp.o.provides: CMakeFiles/PBTest.dir/ProtoTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/PBTest.dir/build.make CMakeFiles/PBTest.dir/ProtoTest.cpp.o.provides.build
.PHONY : CMakeFiles/PBTest.dir/ProtoTest.cpp.o.provides

CMakeFiles/PBTest.dir/ProtoTest.cpp.o.provides.build: CMakeFiles/PBTest.dir/ProtoTest.cpp.o


CMakeFiles/PBTest.dir/message.pb.cc.o: CMakeFiles/PBTest.dir/flags.make
CMakeFiles/PBTest.dir/message.pb.cc.o: message.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PBTest.dir/message.pb.cc.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PBTest.dir/message.pb.cc.o -c /home/ubuntu/MyRep/ToolDir/build/message.pb.cc

CMakeFiles/PBTest.dir/message.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PBTest.dir/message.pb.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/ToolDir/build/message.pb.cc > CMakeFiles/PBTest.dir/message.pb.cc.i

CMakeFiles/PBTest.dir/message.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PBTest.dir/message.pb.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/ToolDir/build/message.pb.cc -o CMakeFiles/PBTest.dir/message.pb.cc.s

CMakeFiles/PBTest.dir/message.pb.cc.o.requires:

.PHONY : CMakeFiles/PBTest.dir/message.pb.cc.o.requires

CMakeFiles/PBTest.dir/message.pb.cc.o.provides: CMakeFiles/PBTest.dir/message.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/PBTest.dir/build.make CMakeFiles/PBTest.dir/message.pb.cc.o.provides.build
.PHONY : CMakeFiles/PBTest.dir/message.pb.cc.o.provides

CMakeFiles/PBTest.dir/message.pb.cc.o.provides.build: CMakeFiles/PBTest.dir/message.pb.cc.o


# Object files for target PBTest
PBTest_OBJECTS = \
"CMakeFiles/PBTest.dir/ProtoTest.cpp.o" \
"CMakeFiles/PBTest.dir/message.pb.cc.o"

# External object files for target PBTest
PBTest_EXTERNAL_OBJECTS =

PBTest: CMakeFiles/PBTest.dir/ProtoTest.cpp.o
PBTest: CMakeFiles/PBTest.dir/message.pb.cc.o
PBTest: CMakeFiles/PBTest.dir/build.make
PBTest: /usr/local/lib/libprotobuf.so
PBTest: CMakeFiles/PBTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable PBTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PBTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PBTest.dir/build: PBTest

.PHONY : CMakeFiles/PBTest.dir/build

CMakeFiles/PBTest.dir/requires: CMakeFiles/PBTest.dir/ProtoTest.cpp.o.requires
CMakeFiles/PBTest.dir/requires: CMakeFiles/PBTest.dir/message.pb.cc.o.requires

.PHONY : CMakeFiles/PBTest.dir/requires

CMakeFiles/PBTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PBTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PBTest.dir/clean

CMakeFiles/PBTest.dir/depend: message.pb.cc
CMakeFiles/PBTest.dir/depend: message.pb.h
	cd /home/ubuntu/MyRep/ToolDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/ToolDir /home/ubuntu/MyRep/ToolDir /home/ubuntu/MyRep/ToolDir/build /home/ubuntu/MyRep/ToolDir/build /home/ubuntu/MyRep/ToolDir/build/CMakeFiles/PBTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PBTest.dir/depend
