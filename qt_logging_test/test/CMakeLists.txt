cmake_minimum_required(VERSION 3.0)
project(test_me)

# GTest
enable_testing()

set (CMAKE_CXX_STANDARD 14)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



# Unit Tests
# Add test cpp file
add_executable( runUnitTests tests.cpp ../sleep.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests ${GTEST_BOTH_LIBRARIES})
target_include_directories(runUnitTests PUBLIC .. ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} )

add_test( runUnitTests runUnitTests )
