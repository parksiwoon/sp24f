# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/student17/linking_lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student17/linking_lab/build

# Include any dependencies generated for this target.
include CMakeFiles/linking_lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linking_lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linking_lab.dir/flags.make

CMakeFiles/linking_lab.dir/main.cpp.o: CMakeFiles/linking_lab.dir/flags.make
CMakeFiles/linking_lab.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student17/linking_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linking_lab.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linking_lab.dir/main.cpp.o -c /home/student17/linking_lab/main.cpp

CMakeFiles/linking_lab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linking_lab.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student17/linking_lab/main.cpp > CMakeFiles/linking_lab.dir/main.cpp.i

CMakeFiles/linking_lab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linking_lab.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student17/linking_lab/main.cpp -o CMakeFiles/linking_lab.dir/main.cpp.s

# Object files for target linking_lab
linking_lab_OBJECTS = \
"CMakeFiles/linking_lab.dir/main.cpp.o"

# External object files for target linking_lab
linking_lab_EXTERNAL_OBJECTS =

linking_lab: CMakeFiles/linking_lab.dir/main.cpp.o
linking_lab: CMakeFiles/linking_lab.dir/build.make
linking_lab: CMakeFiles/linking_lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student17/linking_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linking_lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linking_lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linking_lab.dir/build: linking_lab

.PHONY : CMakeFiles/linking_lab.dir/build

CMakeFiles/linking_lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linking_lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linking_lab.dir/clean

CMakeFiles/linking_lab.dir/depend:
	cd /home/student17/linking_lab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student17/linking_lab /home/student17/linking_lab /home/student17/linking_lab/build /home/student17/linking_lab/build /home/student17/linking_lab/build/CMakeFiles/linking_lab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linking_lab.dir/depend

