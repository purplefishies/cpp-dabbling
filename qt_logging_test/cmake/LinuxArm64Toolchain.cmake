# Specify the cross-compilation toolchain
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Set the cross-compilation prefix
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
set(CMAKE_AR aarch64-linux-gnu-ar)

# Set the compiler flags and options
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8-a")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a")

#set(CMAKE_C_COMPILER_WORKS 1)
#set(CMAKE_CXX_COMPILER_WORKS 1)


# Set the sysroot directory
#set(CMAKE_SYSROOT "/path/to/aarch64-linux-gnu/sysroot")

# Specify the target architecture
set(CMAKE_LIBRARY_ARCHITECTURE "aarch64-linux-gnu")



set(COMPILE_DEFINITIONS_COMMON "-D_VC80_UPGRADE=0x0600 -D_MBCS -D_WINDOWS -D_CRT_SECURE_NO_DEPRECATE")
set(CMAKE_CXX_FLAGS "${WINFLAGS} ${COMPILE_DEFINITIONS_COMMON} -DLINUX -fcompare-debug-second -fno-rtti -fexceptions" CACHE INTERNAL "")
set(CMAKE_C_FLAGS "-w -O2 $(INCLUDES) -DLINUX -fcompare-debug-second" CACHE INTERNAL "")
