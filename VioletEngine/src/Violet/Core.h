#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS
	#ifdef VIOLET_BUILD_DLL
		#define VIOLET_API __declspec(dllexport)
	#else
		#define VIOLET_API __declspec(dllimport)
	#endif
#else
	#error Violet Only Supports Windows
#endif 
