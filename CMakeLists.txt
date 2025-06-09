cmake_minimum_required(VERSION 3.18)
project(cpp-template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main executable sources
include(sources.cmake)

add_executable(cpp-template ${SOURCES})

# Public headers
target_include_directories(cpp-template PRIVATE include)

# Compiler options (optional)
target_compile_features(cpp-template PRIVATE cxx_std_20)
target_compile_options(cpp-template PRIVATE -Wall -Wextra -pedantic)

# Fetch GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Add tests
enable_testing()

include(test_sources.cmake)

add_executable(tests_runner ${TEST_SOURCES})

target_include_directories(tests_runner PRIVATE include)

target_link_libraries(tests_runner gtest_main)

add_test(NAME all_tests COMMAND tests_runner)
