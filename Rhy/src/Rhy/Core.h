#pragma once

#ifdef R_PLATFORM_WINDOWS
	#ifdef R_BUILD_DLL
		#define RHY_API __declspec(dllexport)
	#else
		#define RHY_API __declspec(dllimport)
	#endif
#else
	#error Rhy only supports Windows!
#endif

#ifdef R_DEBUG
	#define R_ENABLE_ASSERTS
#endif

#ifdef R_ENABLE_ASSERTS
	#define R_ASSERT(x, ...) { if(!(x)) { R_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define R_CORE_ASSERT(x, ...) { if(!(x)) { R_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define R_ASSERT(x, ...)
	#define R_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define R_BIND_EVENT_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)

