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
include CMakeFiles/scriptnameerrortest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/scriptnameerrortest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/scriptnameerrortest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scriptnameerrortest.dir/flags.make

CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o: CMakeFiles/scriptnameerrortest.dir/flags.make
CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o: /Users/mac/Workspace/DSL_Interpreter/test/scriptnameerror.cpp
CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o: CMakeFiles/scriptnameerrortest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o -MF CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o.d -o CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o -c /Users/mac/Workspace/DSL_Interpreter/test/scriptnameerror.cpp

CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/Workspace/DSL_Interpreter/test/scriptnameerror.cpp > CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.i

CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/Workspace/DSL_Interpreter/test/scriptnameerror.cpp -o CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.s

# Object files for target scriptnameerrortest
scriptnameerrortest_OBJECTS = \
"CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o"

# External object files for target scriptnameerrortest
scriptnameerrortest_EXTERNAL_OBJECTS =

scriptnameerrortest: CMakeFiles/scriptnameerrortest.dir/test/scriptnameerror.cpp.o
scriptnameerrortest: CMakeFiles/scriptnameerrortest.dir/build.make
scriptnameerrortest: libpharser.a
scriptnameerrortest: librecord.a
scriptnameerrortest: libstep.a
scriptnameerrortest: libstate.a
scriptnameerrortest: lib/libgtest_maind.a
scriptnameerrortest: lib/libgtestd.a
scriptnameerrortest: CMakeFiles/scriptnameerrortest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scriptnameerrortest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scriptnameerrortest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scriptnameerrortest.dir/build: scriptnameerrortest
.PHONY : CMakeFiles/scriptnameerrortest.dir/build

CMakeFiles/scriptnameerrortest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scriptnameerrortest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scriptnameerrortest.dir/clean

CMakeFiles/scriptnameerrortest.dir/depend:
	cd /Users/mac/Workspace/DSL_Interpreter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build /Users/mac/Workspace/DSL_Interpreter/build/CMakeFiles/scriptnameerrortest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/scriptnameerrortest.dir/depend

