cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
project(STDStreamTimerTesting)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(STDStreamTimerTesting test/test.cpp)
target_link_libraries(STDStreamTimerTesting GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(STDStreamTimerTesting)

add_library(STDStreamTimer INTERFACE)