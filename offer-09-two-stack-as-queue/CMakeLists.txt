cmake_minimum_required(VERSION 3.14)
project(offer09)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(solution_test_${PROJECT_NAME})
target_sources(solution_test_${PROJECT_NAME} PUBLIC solution_test.cpp)
target_link_libraries(solution_test_${PROJECT_NAME} GTest::gtest_main GTest::gmock_main)
include(GoogleTest)
gtest_discover_tests(solution_test_${PROJECT_NAME})

add_executable(main_${PROJECT_NAME})
target_sources(main_${PROJECT_NAME} PUBLIC main.cpp)
target_include_directories(main_${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
