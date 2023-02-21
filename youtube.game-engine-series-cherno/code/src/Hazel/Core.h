#pragma once

#ifndef HZ_PLATFORM_LINUX 
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#else 
    #error Hazel only supports linux compilation.
#endif