MESSAGE(STATUS "Took toolchain-visual")

set(CMAKE_SYSTEM_NAME WindowsCE)
set(CMAKE_SYSTEM_VERSION 8.0)
set(CMAKE_SYSTEM_PROCESSOR arm)


SET(CMAKE_C_COMPILER   "C:/VisualStudio9/VC/ce/bin/x86_arm/cl.exe")
SET(CMAKE_CXX_COMPILER  "C:/VisualStudio9/VC/ce/bin/x86_arm/cl.exe" )

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(WINFLAGS "/D \"_USE_32BIT_TIME_T\" /D _WIN32_WCE=0x500 /D \"UNDER_CE\" /D \"WINCE\" /D \"_UNICODE\" /D \"UNICODE\" /D \"ARM\" /D \"_ARM_\" /D \"USE_32BIT_TIME_T\"")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_CXX_FLAGS "${WINFLAGS} ${COMPILE_DEFINITIONS_COMMON}  /Gm /EHsc /MTd /fp:fast /Zc:wchar_t- /GR- /W3 /c /Zi /TP" )

set(CMAKE_CXX_FLAGS_DEBUG "/RTC1 -D_DEBUG -D_WINDOWS" )
set(CMAKE_CXX_FLAGS_RELEASE "/D \"NDEBUG\"" )
