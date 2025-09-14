

# Specify the cross-compilation toolchain
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Set the cross-compilation prefix
set(CMAKE_C_COMPILER /home/geodetics/Toradex/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /home/geodetics/Toradex/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ )
set(CMAKE_AR aarch64-linux-gnu-ar)
set(CMAKE_SYSROOT "/home/geodetics/Toradex/AevexImageSDK/sysroots/armv7at2hf-neon-angstrom-linux-gnueabi")

# Set the compiler flags and options
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcompare-debug-second -Wno-unused-result -march=armv7-a -fno-tree-vectorize -mthumb-interwork -mfloat-abi=hard -mtune=cortex-a9  -fexceptions")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcompare-debug-second -Wno-unused-result -march=armv7-a -fno-tree-vectorize -mthumb-interwork -mfloat-abi=hard -mtune=cortex-a9  -fno-rtti -fexceptions")

# Set the sysroot directory


# Specify the target architecture
set(CMAKE_LIBRARY_ARCHITECTURE "aarch32-linux-gnu")
