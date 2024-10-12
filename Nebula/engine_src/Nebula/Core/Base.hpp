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
    #define NB_ENABLE_ASSERTS
#else
    // No-op when not in debug mode
    #define NB_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)

#define NB_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#include "Nebula/Core/Log.hpp"
#include "Nebula/Core/Assert.hpp"