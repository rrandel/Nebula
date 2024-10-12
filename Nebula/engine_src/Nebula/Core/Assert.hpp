#pragma once

#include "Nebula/Core/Base.hpp"
#include "Nebula/Core/Log.hpp"
#include <filesystem>

#ifdef NB_ENABLE_ASSERTS
	#define NB_ASSERT(x, ...) { if(!(x)) { NB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NB_CORE_ASSERT(x, ...) { if(!(x)) { NB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NB_ASSERT(x, ...)
	#define NB_CORE_ASSERT(x, ...)
#endif