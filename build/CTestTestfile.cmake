# CMake generated Testfile for 
# Source directory: /Users/mac/Workspace/DSL_Interpreter
# Build directory: /Users/mac/Workspace/DSL_Interpreter/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Recordtest "testrecord")
set_tests_properties(Recordtest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;68;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Computetest "/Users/mac/Workspace/DSL_Interpreter/build/computetest")
set_tests_properties(Computetest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;73;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Comparetest "/Users/mac/Workspace/DSL_Interpreter/build/comparetest")
set_tests_properties(Comparetest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;78;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Defaulttest "/Users/mac/Workspace/DSL_Interpreter/build/defaulttest")
set_tests_properties(Defaulttest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;83;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Jumpttest "/Users/mac/Workspace/DSL_Interpreter/build/jumptest")
set_tests_properties(Jumpttest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;88;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Outputtest "/Users/mac/Workspace/DSL_Interpreter/build/outputtest")
set_tests_properties(Outputtest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;93;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Timeouttest "/Users/mac/Workspace/DSL_Interpreter/build/timeouttest")
set_tests_properties(Timeouttest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;98;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Statetest "/Users/mac/Workspace/DSL_Interpreter/build/statetest")
set_tests_properties(Statetest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;103;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Pharsertest "/Users/mac/Workspace/DSL_Interpreter/build/pharsertest")
set_tests_properties(Pharsertest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;108;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
add_test(Concurrencytest "/Users/mac/Workspace/DSL_Interpreter/build/concurrencytest")
set_tests_properties(Concurrencytest PROPERTIES  _BACKTRACE_TRIPLES "/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;113;add_test;/Users/mac/Workspace/DSL_Interpreter/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
