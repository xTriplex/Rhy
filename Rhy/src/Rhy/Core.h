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

