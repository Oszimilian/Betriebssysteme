# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Git/Betriebssysteme/Praktikum2/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Git/Betriebssysteme/Praktikum2/task2/build

# Include any dependencies generated for this target.
include CMakeFiles/task2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2.dir/flags.make

CMakeFiles/task2.dir/inc_threads.c.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/inc_threads.c.o: ../inc_threads.c
CMakeFiles/task2.dir/inc_threads.c.o: CMakeFiles/task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Git/Betriebssysteme/Praktikum2/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task2.dir/inc_threads.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/task2.dir/inc_threads.c.o -MF CMakeFiles/task2.dir/inc_threads.c.o.d -o CMakeFiles/task2.dir/inc_threads.c.o -c /home/user/Git/Betriebssysteme/Praktikum2/task2/inc_threads.c

CMakeFiles/task2.dir/inc_threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task2.dir/inc_threads.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/Git/Betriebssysteme/Praktikum2/task2/inc_threads.c > CMakeFiles/task2.dir/inc_threads.c.i

CMakeFiles/task2.dir/inc_threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task2.dir/inc_threads.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/Git/Betriebssysteme/Praktikum2/task2/inc_threads.c -o CMakeFiles/task2.dir/inc_threads.c.s

# Object files for target task2
task2_OBJECTS = \
"CMakeFiles/task2.dir/inc_threads.c.o"

# External object files for target task2
task2_EXTERNAL_OBJECTS =

task2: CMakeFiles/task2.dir/inc_threads.c.o
task2: CMakeFiles/task2.dir/build.make
task2: CMakeFiles/task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Git/Betriebssysteme/Praktikum2/task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2.dir/build: task2
.PHONY : CMakeFiles/task2.dir/build

CMakeFiles/task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task2.dir/clean

CMakeFiles/task2.dir/depend:
	cd /home/user/Git/Betriebssysteme/Praktikum2/task2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Git/Betriebssysteme/Praktikum2/task2 /home/user/Git/Betriebssysteme/Praktikum2/task2 /home/user/Git/Betriebssysteme/Praktikum2/task2/build /home/user/Git/Betriebssysteme/Praktikum2/task2/build /home/user/Git/Betriebssysteme/Praktikum2/task2/build/CMakeFiles/task2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task2.dir/depend

