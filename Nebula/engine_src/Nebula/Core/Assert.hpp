#pragma once

#include "Nebula/Core/Base.hpp"
#include "Nebula/Core/Log.hpp"
#include <filesystem>

#ifdef NB_ENABLE_ASSERTS
    // Use NB_DEBUGBREAK based on platform defined in Base.hpp
	#define NB_ASSERT(x, ...) { if(!(x)) { NB_ERROR("Assertion Failed: {0}", __VA_ARGS__); NB_DEBUGBREAK(); } }
	#define NB_CORE_ASSERT(x, ...) { if(!(x)) { NB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); NB_DEBUGBREAK(); } }
#else
    // Disable asserts when NB_ENABLE_ASSERTS is not defined
	#define NB_ASSERT(x, ...)
	#define NB_CORE_ASSERT(x, ...)
#endif

