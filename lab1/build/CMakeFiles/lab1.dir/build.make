# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/fy/Desktop/SJTU/IS206/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fy/Desktop/SJTU/IS206/lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1.dir/flags.make

CMakeFiles/lab1.dir/memory_manage.c.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/memory_manage.c.o: ../memory_manage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fy/Desktop/SJTU/IS206/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab1.dir/memory_manage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1.dir/memory_manage.c.o -c /home/fy/Desktop/SJTU/IS206/lab1/memory_manage.c

CMakeFiles/lab1.dir/memory_manage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1.dir/memory_manage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fy/Desktop/SJTU/IS206/lab1/memory_manage.c > CMakeFiles/lab1.dir/memory_manage.c.i

CMakeFiles/lab1.dir/memory_manage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1.dir/memory_manage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fy/Desktop/SJTU/IS206/lab1/memory_manage.c -o CMakeFiles/lab1.dir/memory_manage.c.s

# Object files for target lab1
lab1_OBJECTS = \
"CMakeFiles/lab1.dir/memory_manage.c.o"

# External object files for target lab1
lab1_EXTERNAL_OBJECTS =

lab1: CMakeFiles/lab1.dir/memory_manage.c.o
lab1: CMakeFiles/lab1.dir/build.make
lab1: CMakeFiles/lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fy/Desktop/SJTU/IS206/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1.dir/build: lab1

.PHONY : CMakeFiles/lab1.dir/build

CMakeFiles/lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab1.dir/clean

CMakeFiles/lab1.dir/depend:
	cd /home/fy/Desktop/SJTU/IS206/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fy/Desktop/SJTU/IS206/lab1 /home/fy/Desktop/SJTU/IS206/lab1 /home/fy/Desktop/SJTU/IS206/lab1/build /home/fy/Desktop/SJTU/IS206/lab1/build /home/fy/Desktop/SJTU/IS206/lab1/build/CMakeFiles/lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab1.dir/depend
