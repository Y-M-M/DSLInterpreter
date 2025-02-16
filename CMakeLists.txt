cmake_minimum_required(VERSION 3.10)   # 指定最低 CMake 版本

project(DSLInterpreter VERSION 1.0)          # 定义项目名称和版本

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找并链接 GoogleTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# 添加链接库
add_library(record src/record.cpp)
add_library(step src/steps.cpp)
add_library(state src/state.cpp)
add_library(pharser src/pharser.cpp)

# 添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加源文件
add_executable(DSLInterpreter src/main.cpp src/pharser.cpp src/record.cpp src/state.cpp src/steps.cpp)  # 创建一个可执行文件目标 MyExecutable

target_link_libraries(DSLInterpreter record step state pharser)


# 使用 FetchContent 模組
include(FetchContent)
# 下載和引入 Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)



# 建立测试用的的可执行文件
add_executable(recordtest test/recordtest.cpp)
add_executable(comparetest test/comparetest.cpp)
add_executable(computetest test/computetest.cpp)
add_executable(defaulttest test/defaulttest.cpp)
add_executable(jumptest test/jumptest.cpp)
add_executable(outputtest test/outputtest.cpp)
add_executable(timeouttest test/timeouttest.cpp)
add_executable(statetest test/statetest.cpp)
add_executable(pharsertest test/pharsertest.cpp)
add_executable(concurrencytest test/concurrencytest.cpp)

# 连接
target_link_libraries(recordtest PRIVATE record gtest_main)
target_link_libraries(comparetest PRIVATE step gtest_main)
target_link_libraries(computetest PRIVATE step gtest_main)
target_link_libraries(defaulttest PRIVATE step gtest_main)
target_link_libraries(jumptest PRIVATE step gtest_main)
target_link_libraries(outputtest PRIVATE step gtest_main)
target_link_libraries(timeouttest PRIVATE step gtest_main)
target_link_libraries(statetest PRIVATE state gtest_main)
target_link_libraries(pharsertest PRIVATE pharser record step state gtest_main)
target_link_libraries(concurrencytest PRIVATE pharser record step state gtest_main ${CMAKE_THREAD_LIBS_INIT})

# 開啟 CMake 測試
enable_testing()

# 添加测试
add_test(
    NAME Recordtest
    COMMAND testrecord
)

add_test(
    NAME Computetest
    COMMAND computetest
)

add_test(
    NAME Comparetest
    COMMAND comparetest
)

add_test(
    NAME Defaulttest
    COMMAND defaulttest
)

add_test(
    NAME Jumpttest
    COMMAND jumptest
)

add_test(
    NAME Outputtest
    COMMAND outputtest
)

add_test(
    NAME Timeouttest
    COMMAND timeouttest
)

add_test(
    NAME Statetest
    COMMAND statetest
)

add_test(
    NAME Pharsertest
    COMMAND pharsertest
)

add_test(
    NAME Concurrencytest
    COMMAND concurrencytest
)

# 检查内存是否泄漏
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")





