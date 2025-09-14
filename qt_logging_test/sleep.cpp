#include "sleep.h"
#include <iostream>

namespace Geodetics
{
#ifdef WIN32
#include <windows.h>

int GeoSleep(unsigned int seconds)
{
    // std::cout << "FOO \n";
    Sleep(seconds * 1000);
    // std::cout << "BAR \n";
    return seconds;
}

#elif LINUX
#include <unistd.h>

int GeoSleep(unsigned int seconds )
{
  return sleep(seconds);
}

#endif

};
