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

# Utility rule file for testtarget.

# Include the progress variables for this target.
include CMakeFiles/testtarget.dir/progress.make

CMakeFiles/testtarget:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/MyRep/ToolDir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Intermediate BLAS_LAPACK_wrappers target"
	echo ehehehe

testtarget: CMakeFiles/testtarget
testtarget: CMakeFiles/testtarget.dir/build.make

.PHONY : testtarget

# Rule to build all files generated by this target.
CMakeFiles/testtarget.dir/build: testtarget

.PHONY : CMakeFiles/testtarget.dir/build

CMakeFiles/testtarget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testtarget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testtarget.dir/clean

CMakeFiles/testtarget.dir/depend:
	cd /home/ubuntu/MyRep/ToolDir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/MyRep/ToolDir /home/ubuntu/MyRep/ToolDir /home/ubuntu/MyRep/ToolDir/build /home/ubuntu/MyRep/ToolDir/build /home/ubuntu/MyRep/ToolDir/build/CMakeFiles/testtarget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testtarget.dir/depend
