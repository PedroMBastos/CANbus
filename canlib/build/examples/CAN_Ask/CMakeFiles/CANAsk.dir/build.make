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
include examples/CAN_Ask/CMakeFiles/CANAsk.dir/depend.make

# Include the progress variables for this target.
include examples/CAN_Ask/CMakeFiles/CANAsk.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CAN_Ask/CMakeFiles/CANAsk.dir/flags.make

examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.o: examples/CAN_Ask/CMakeFiles/CANAsk.dir/flags.make
examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.o: ../examples/CAN_Ask/ask.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedro/canlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.o"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CANAsk.dir/ask.c.o   -c /home/pedro/canlib/examples/CAN_Ask/ask.c

examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CANAsk.dir/ask.c.i"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pedro/canlib/examples/CAN_Ask/ask.c > CMakeFiles/CANAsk.dir/ask.c.i

examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CANAsk.dir/ask.c.s"
	cd /home/pedro/canlib/build/examples/CAN_Ask && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pedro/canlib/examples/CAN_Ask/ask.c -o CMakeFiles/CANAsk.dir/ask.c.s

# Object files for target CANAsk
CANAsk_OBJECTS = \
"CMakeFiles/CANAsk.dir/ask.c.o"

# External object files for target CANAsk
CANAsk_EXTERNAL_OBJECTS =

../output/bin/CANAsk: examples/CAN_Ask/CMakeFiles/CANAsk.dir/ask.c.o
../output/bin/CANAsk: examples/CAN_Ask/CMakeFiles/CANAsk.dir/build.make
../output/bin/CANAsk: ../output/lib/libcan_driver.so
../output/bin/CANAsk: examples/CAN_Ask/CMakeFiles/CANAsk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedro/canlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../output/bin/CANAsk"
	cd /home/pedro/canlib/build/examples/CAN_Ask && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CANAsk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CAN_Ask/CMakeFiles/CANAsk.dir/build: ../output/bin/CANAsk

.PHONY : examples/CAN_Ask/CMakeFiles/CANAsk.dir/build

examples/CAN_Ask/CMakeFiles/CANAsk.dir/clean:
	cd /home/pedro/canlib/build/examples/CAN_Ask && $(CMAKE_COMMAND) -P CMakeFiles/CANAsk.dir/cmake_clean.cmake
.PHONY : examples/CAN_Ask/CMakeFiles/CANAsk.dir/clean

examples/CAN_Ask/CMakeFiles/CANAsk.dir/depend:
	cd /home/pedro/canlib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedro/canlib /home/pedro/canlib/examples/CAN_Ask /home/pedro/canlib/build /home/pedro/canlib/build/examples/CAN_Ask /home/pedro/canlib/build/examples/CAN_Ask/CMakeFiles/CANAsk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CAN_Ask/CMakeFiles/CANAsk.dir/depend

