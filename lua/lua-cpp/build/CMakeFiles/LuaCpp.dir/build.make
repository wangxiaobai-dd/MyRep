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
CMAKE_SOURCE_DIR = /home/ubuntu/MyRep/lua/lua-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/MyRep/lua/lua-cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/LuaCpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LuaCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LuaCpp.dir/flags.make

CMakeFiles/LuaCpp.dir/LuaCppMain.o: CMakeFiles/LuaCpp.dir/flags.make
CMakeFiles/LuaCpp.dir/LuaCppMain.o: ../LuaCppMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/MyRep/lua/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LuaCpp.dir/LuaCppMain.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LuaCpp.dir/LuaCppMain.o -c /home/ubuntu/MyRep/lua/lua-cpp/LuaCppMain.cpp

CMakeFiles/LuaCpp.dir/LuaCppMain.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LuaCpp.dir/LuaCppMain.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/MyRep/lua/lua-cpp/LuaCppMain.cpp > CMakeFiles/LuaCpp.dir/LuaCppMain.i

CMakeFiles/LuaCpp.dir/LuaCppMain.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LuaCpp.dir/LuaCppMain.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/MyRep/lua/lua-cpp/LuaCppMain.cpp -o CMakeFiles/LuaCpp.dir/LuaCppMain.s

# Object files for target LuaCpp
LuaCpp_OBJECTS = \
"CMakeFiles/LuaCpp.dir/LuaCppMain.o"

# External object files for target LuaCpp
LuaCpp_EXTERNAL_OBJECTS =

../LuaCPP: CMakeFiles/LuaCpp.dir/LuaCppMain.o
../LuaCPP: CMakeFiles/LuaCpp.dir/build.make
../LuaCPP: CMakeFiles/LuaCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/MyRep/lua/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../LuaCPP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LuaCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LuaCpp.dir/build: ../LuaCPP

.PHONY : CMakeFiles/LuaCpp.dir/build

CMakeFiles/LuaCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LuaCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LuaCpp.dir/clean

CMakeFiles/LuaCpp.dir/depend:
	cd /home/ubuntu/MyRep/lua/lua-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/lua/lua-cpp /home/ubuntu/MyRep/lua/lua-cpp /home/ubuntu/MyRep/lua/lua-cpp/build /home/ubuntu/MyRep/lua/lua-cpp/build /home/ubuntu/MyRep/lua/lua-cpp/build/CMakeFiles/LuaCpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LuaCpp.dir/depend

