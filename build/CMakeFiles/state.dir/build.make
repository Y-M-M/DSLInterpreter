# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/Workspace/DSL_Interpreter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/Workspace/DSL_Interpreter/build

# Include any dependencies generated for this target.
include CMakeFiles/state.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/state.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/state.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/state.dir/flags.make

CMakeFiles/state.dir/src/state.cpp.o: CMakeFiles/state.dir/flags.make
CMakeFiles/state.dir/src/state.cpp.o: /Users/mac/Workspace/DSL_Interpreter/src/state.cpp
CMakeFiles/state.dir/src/state.cpp.o: CMakeFiles/state.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/state.dir/src/state.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/state.dir/src/state.cpp.o -MF CMakeFiles/state.dir/src/state.cpp.o.d -o CMakeFiles/state.dir/src/state.cpp.o -c /Users/mac/Workspace/DSL_Interpreter/src/state.cpp

CMakeFiles/state.dir/src/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/state.dir/src/state.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/Workspace/DSL_Interpreter/src/state.cpp > CMakeFiles/state.dir/src/state.cpp.i

CMakeFiles/state.dir/src/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/state.dir/src/state.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/Workspace/DSL_Interpreter/src/state.cpp -o CMakeFiles/state.dir/src/state.cpp.s

# Object files for target state
state_OBJECTS = \
"CMakeFiles/state.dir/src/state.cpp.o"

# External object files for target state
state_EXTERNAL_OBJECTS =

libstate.a: CMakeFiles/state.dir/src/state.cpp.o
libstate.a: CMakeFiles/state.dir/build.make
libstate.a: CMakeFiles/state.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstate.a"
	$(CMAKE_COMMAND) -P CMakeFiles/state.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/state.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/state.dir/build: libstate.a
.PHONY : CMakeFiles/state.dir/build

CMakeFiles/state.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/state.dir/cmake_clean.cmake
.PHONY : CMakeFiles/state.dir/clean

CMakeFiles/state.dir/depend:
	cd /Users/mac/Workspace/DSL_Interpreter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles/state.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/state.dir/depend

