# Specify the cross-compilation toolchain
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Specify the target architecture
set(CMAKE_LIBRARY_ARCHITECTURE "aarch64-linux-gnu")
set(COMPILE_DEFINITIONS_COMMON "")

# cmake_minimum_required(VERSION 3.0)
cmake_minimum_required(VERSION 3.20...3.28)

# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g3 -ggdb3 -O0 -gdwarf-2")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -ggdb3 -O0 -gdwarf-2")
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -ggdb3 -O0")
