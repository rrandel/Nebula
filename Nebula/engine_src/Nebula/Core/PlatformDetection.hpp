#pragma once

// Platform detection using predefined macros
#ifndef NB_PLATFORM_WINDOWS
    #if defined(_WIN32) && defined(_WIN64)
        // Windows x64
        #define NB_PLATFORM_WINDOWS
    #elif defined(_WIN32)
        // Windows x86
        #error "x86 Builds are not supported!"
    #endif
#endif

#ifndef NB_PLATFORM_MACOS
    #if defined(__APPLE__) && defined(__MACH__)
        #include <TargetConditionals.h>
        // Check all Apple platforms
        #if TARGET_OS_MAC == 1
            // macOS
            #define NB_PLATFORM_MACOS
        #elif TARGET_OS_IPHONE == 1
            // iOS
            #define NB_PLATFORM_IOS
        #elif TARGET_IPHONE_SIMULATOR == 1
            // iOS Simulator
            #error "iOS Simulator is not supported!"
        #else
            #error "Unknown Apple platform!"
        #endif
    #endif
#endif

#ifndef NB_PLATFORM_ANDROID
    #if defined(__ANDROID__)
        // Android platform
        #define NB_PLATFORM_ANDROID
    #endif
#endif

#ifndef NB_PLATFORM_LINUX
    #if defined(__linux__)
        // Linux platform
        #define NB_PLATFORM_LINUX
    #endif
#endif

#if !defined(NB_PLATFORM_WINDOWS) && !defined(NB_PLATFORM_MACOS) && !defined(NB_PLATFORM_IOS) && !defined(NB_PLATFORM_ANDROID) && !defined(NB_PLATFORM_LINUX)
    #error "Unknown platform!"
#endif
