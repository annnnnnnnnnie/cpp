cmake_minimum_required(VERSION 3.14)
project(784)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  solution_test
  solution_test.cpp
)
target_link_libraries(
  solution_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(solution_test)