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
include CMakeFiles/timeouttest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/timeouttest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/timeouttest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timeouttest.dir/flags.make

CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o: CMakeFiles/timeouttest.dir/flags.make
CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o: /Users/mac/Workspace/DSL_Interpreter/test/timeouttest.cpp
CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o: CMakeFiles/timeouttest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o -MF CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o.d -o CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o -c /Users/mac/Workspace/DSL_Interpreter/test/timeouttest.cpp

CMakeFiles/timeouttest.dir/test/timeouttest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/timeouttest.dir/test/timeouttest.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/Workspace/DSL_Interpreter/test/timeouttest.cpp > CMakeFiles/timeouttest.dir/test/timeouttest.cpp.i

CMakeFiles/timeouttest.dir/test/timeouttest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/timeouttest.dir/test/timeouttest.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/Workspace/DSL_Interpreter/test/timeouttest.cpp -o CMakeFiles/timeouttest.dir/test/timeouttest.cpp.s

# Object files for target timeouttest
timeouttest_OBJECTS = \
"CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o"

# External object files for target timeouttest
timeouttest_EXTERNAL_OBJECTS =

timeouttest: CMakeFiles/timeouttest.dir/test/timeouttest.cpp.o
timeouttest: CMakeFiles/timeouttest.dir/build.make
timeouttest: libstep.a
timeouttest: lib/libgtest_maind.a
timeouttest: lib/libgtestd.a
timeouttest: CMakeFiles/timeouttest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable timeouttest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timeouttest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/timeouttest.dir/build: timeouttest
.PHONY : CMakeFiles/timeouttest.dir/build

CMakeFiles/timeouttest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/timeouttest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/timeouttest.dir/clean

CMakeFiles/timeouttest.dir/depend:
	cd /Users/mac/Workspace/DSL_Interpreter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles/timeouttest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/timeouttest.dir/depend

