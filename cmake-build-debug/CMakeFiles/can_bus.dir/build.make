# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/emanuelalkobi/CLionProjects/can_bus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/can_bus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/can_bus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/can_bus.dir/flags.make

CMakeFiles/can_bus.dir/main.c.o: CMakeFiles/can_bus.dir/flags.make
CMakeFiles/can_bus.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/can_bus.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/can_bus.dir/main.c.o   -c /Users/emanuelalkobi/CLionProjects/can_bus/main.c

CMakeFiles/can_bus.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/can_bus.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/emanuelalkobi/CLionProjects/can_bus/main.c > CMakeFiles/can_bus.dir/main.c.i

CMakeFiles/can_bus.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/can_bus.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/emanuelalkobi/CLionProjects/can_bus/main.c -o CMakeFiles/can_bus.dir/main.c.s

CMakeFiles/can_bus.dir/func.c.o: CMakeFiles/can_bus.dir/flags.make
CMakeFiles/can_bus.dir/func.c.o: ../func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/can_bus.dir/func.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/can_bus.dir/func.c.o   -c /Users/emanuelalkobi/CLionProjects/can_bus/func.c

CMakeFiles/can_bus.dir/func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/can_bus.dir/func.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/emanuelalkobi/CLionProjects/can_bus/func.c > CMakeFiles/can_bus.dir/func.c.i

CMakeFiles/can_bus.dir/func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/can_bus.dir/func.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/emanuelalkobi/CLionProjects/can_bus/func.c -o CMakeFiles/can_bus.dir/func.c.s

# Object files for target can_bus
can_bus_OBJECTS = \
"CMakeFiles/can_bus.dir/main.c.o" \
"CMakeFiles/can_bus.dir/func.c.o"

# External object files for target can_bus
can_bus_EXTERNAL_OBJECTS =

can_bus: CMakeFiles/can_bus.dir/main.c.o
can_bus: CMakeFiles/can_bus.dir/func.c.o
can_bus: CMakeFiles/can_bus.dir/build.make
can_bus: CMakeFiles/can_bus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable can_bus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/can_bus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/can_bus.dir/build: can_bus

.PHONY : CMakeFiles/can_bus.dir/build

CMakeFiles/can_bus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/can_bus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/can_bus.dir/clean

CMakeFiles/can_bus.dir/depend:
	cd /Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/emanuelalkobi/CLionProjects/can_bus /Users/emanuelalkobi/CLionProjects/can_bus /Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug /Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug /Users/emanuelalkobi/CLionProjects/can_bus/cmake-build-debug/CMakeFiles/can_bus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/can_bus.dir/depend

