cmake_minimum_required(VERSION 3.12)
project(GSerialMockTest)
enable_testing()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

find_package(fmt CONFIG REQUIRED)
find_package(log4cxx CONFIG REQUIRED)

find_package(PkgConfig REQUIRED)

pkg_check_modules(APR REQUIRED apr-1)
pkg_check_modules(APRUTIL REQUIRED apr-util-1)




set (CMAKE_CXX_STANDARD 11)

include_directories(${APR_INCLUDE_DIRS} ${APRUTIL_INCLUDE_DIRS}  ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} )
link_directories(${APR_LIBRARY_DIRS} ${APRUTIL_LIBRARY_DIRS})

add_executable(GSerialMockTest gserial_test.cpp sleep.cpp)

add_executable(logtest logtest.cpp)
target_link_libraries(logtest PRIVATE fmt::fmt log4cxx
  ${APR_LIBRARIES}
  ${APRUTIL_LIBRARIES}
)

if( LINUX )
  target_compile_definitions(GSerialMockTest PUBLIC -DLINUX )
endif()
target_link_libraries(GSerialMockTest PRIVATE  GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main )

# Enable C++11 features
#set_property(TARGET GSerialMockTest PROPERTY CXX_STANDARD 11)
#set_property(TARGET GSerialMockTest PROPERTY CXX_STANDARD_REQUIRED ON)

add_test(GSerialMockTest GSerialMockTest)
gtest_discover_tests(GSerialMockTest)

