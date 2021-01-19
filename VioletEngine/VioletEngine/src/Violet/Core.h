#pragma once

#ifdef V_PLATFORM_WINDOWS
	#ifdef VIOLET_BUILD_DLL
		#define VIOLET_API __declspec(dllexport)
	#else
		#define VIOLET_API __declspec(dllimport)
	#endif // V_BUILD_DLL
#else
	#error Violet Only Supports Windows
#endif //V_PLATFORM_WINDOWS
