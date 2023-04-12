#pragma once

#ifdef ZO_PLATFORM_WINDOWS
	#ifdef ZO_BUILD_DLL
		#define ZEO_API __declspec(dllexport)
	#else		
		#define ZEO_API __declspec(dllimport)
	#endif // ZO_BULID_DLL 
#else
	#error Zeo only supports Windows!
#endif // ZO_PLATFORM_WINDOWS
