# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "Z:\Projects\School Work\CS300\Assignment3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Assignment3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment3.dir/flags.make

CMakeFiles/Assignment3.dir/main.cpp.obj: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment3.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment3.dir\main.cpp.obj -c "Z:\Projects\School Work\CS300\Assignment3\main.cpp"

CMakeFiles/Assignment3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment3.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "Z:\Projects\School Work\CS300\Assignment3\main.cpp" > CMakeFiles\Assignment3.dir\main.cpp.i

CMakeFiles/Assignment3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment3.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "Z:\Projects\School Work\CS300\Assignment3\main.cpp" -o CMakeFiles\Assignment3.dir\main.cpp.s

CMakeFiles/Assignment3.dir/Node.cpp.obj: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/Node.cpp.obj: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment3.dir/Node.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment3.dir\Node.cpp.obj -c "Z:\Projects\School Work\CS300\Assignment3\Node.cpp"

CMakeFiles/Assignment3.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment3.dir/Node.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "Z:\Projects\School Work\CS300\Assignment3\Node.cpp" > CMakeFiles\Assignment3.dir\Node.cpp.i

CMakeFiles/Assignment3.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment3.dir/Node.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "Z:\Projects\School Work\CS300\Assignment3\Node.cpp" -o CMakeFiles\Assignment3.dir\Node.cpp.s

CMakeFiles/Assignment3.dir/Stack.cpp.obj: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/Stack.cpp.obj: ../Stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Assignment3.dir/Stack.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment3.dir\Stack.cpp.obj -c "Z:\Projects\School Work\CS300\Assignment3\Stack.cpp"

CMakeFiles/Assignment3.dir/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment3.dir/Stack.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "Z:\Projects\School Work\CS300\Assignment3\Stack.cpp" > CMakeFiles\Assignment3.dir\Stack.cpp.i

CMakeFiles/Assignment3.dir/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment3.dir/Stack.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "Z:\Projects\School Work\CS300\Assignment3\Stack.cpp" -o CMakeFiles\Assignment3.dir\Stack.cpp.s

# Object files for target Assignment3
Assignment3_OBJECTS = \
"CMakeFiles/Assignment3.dir/main.cpp.obj" \
"CMakeFiles/Assignment3.dir/Node.cpp.obj" \
"CMakeFiles/Assignment3.dir/Stack.cpp.obj"

# External object files for target Assignment3
Assignment3_EXTERNAL_OBJECTS =

Assignment3.exe: CMakeFiles/Assignment3.dir/main.cpp.obj
Assignment3.exe: CMakeFiles/Assignment3.dir/Node.cpp.obj
Assignment3.exe: CMakeFiles/Assignment3.dir/Stack.cpp.obj
Assignment3.exe: CMakeFiles/Assignment3.dir/build.make
Assignment3.exe: CMakeFiles/Assignment3.dir/linklibs.rsp
Assignment3.exe: CMakeFiles/Assignment3.dir/objects1.rsp
Assignment3.exe: CMakeFiles/Assignment3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Assignment3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment3.dir/build: Assignment3.exe
.PHONY : CMakeFiles/Assignment3.dir/build

CMakeFiles/Assignment3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment3.dir/clean

CMakeFiles/Assignment3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "Z:\Projects\School Work\CS300\Assignment3" "Z:\Projects\School Work\CS300\Assignment3" "Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug" "Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug" "Z:\Projects\School Work\CS300\Assignment3\cmake-build-debug\CMakeFiles\Assignment3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment3.dir/depend
