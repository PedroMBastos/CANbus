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
CMAKE_SOURCE_DIR = /home/pedro/canlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedro/canlib/build

# Include any dependencies generated for this target.
include examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/depend.make

# Include the progress variables for this target.
include examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/flags.make

examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.o: examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/flags.make
examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.o: ../examples/CAN_Ask/ask.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedro/canlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.o"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CAN_Ask.dir/ask.c.o   -c /home/pedro/canlib/examples/CAN_Ask/ask.c

examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CAN_Ask.dir/ask.c.i"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pedro/canlib/examples/CAN_Ask/ask.c > CMakeFiles/CAN_Ask.dir/ask.c.i

examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CAN_Ask.dir/ask.c.s"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pedro/canlib/examples/CAN_Ask/ask.c -o CMakeFiles/CAN_Ask.dir/ask.c.s

# Object files for target CAN_Ask
CAN_Ask_OBJECTS = \
"CMakeFiles/CAN_Ask.dir/ask.c.o"

# External object files for target CAN_Ask
CAN_Ask_EXTERNAL_OBJECTS =

../output/bin/CAN_Ask: examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/ask.c.o
../output/bin/CAN_Ask: examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/build.make
../output/bin/CAN_Ask: ../output/lib/libcan_driver.so
../output/bin/CAN_Ask: examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedro/canlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../output/bin/CAN_Ask"
	cd /home/pedro/canlib/build/examples/CAN_Ask && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CAN_Ask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/build: ../output/bin/CAN_Ask

.PHONY : examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/build

examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/clean:
	cd /home/pedro/canlib/build/examples/CAN_Ask && $(CMAKE_COMMAND) -P CMakeFiles/CAN_Ask.dir/cmake_clean.cmake
.PHONY : examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/clean

examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/depend:
	cd /home/pedro/canlib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedro/canlib /home/pedro/canlib/examples/CAN_Ask /home/pedro/canlib/build /home/pedro/canlib/build/examples/CAN_Ask /home/pedro/canlib/build/examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CAN_Ask/CMakeFiles/CAN_Ask.dir/depend
