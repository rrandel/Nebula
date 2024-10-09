#pragma once
#include "PlatformDetection.hpp"

// Define debug break functionality based on platform
#ifdef NB_DEBUG
    #if defined(NB_PLATFORM_WINDOWS)
        #ifndef NB_DEBUGBREAK
            #define NB_DEBUGBREAK() __debugbreak()
        #endif
    #elif defined(NB_PLATFORM_LINUX)
        #include <signal.h>
        #ifndef NB_DEBUGBREAK
            #define NB_DEBUGBREAK() raise(SIGTRAP)
        #endif
    #else
        #error "Debugbreak is not supported on this platform!"
    #endif
#else
    // No-op when not in debug mode
    #define NB_DEBUGBREAK()
#endif