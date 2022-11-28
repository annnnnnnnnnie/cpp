cmake_minimum_required(VERSION 3.14)
project(1758)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(solution_test)
target_sources(solution_test PUBLIC solution_test.cpp)
target_link_libraries(solution_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(solution_test)

add_executable(main)
target_sources(main PUBLIC main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
