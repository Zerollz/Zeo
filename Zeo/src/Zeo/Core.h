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

#ifdef ZO_ENABLE_ASSERSTS
	#define ZO_ASSERT(x, ...) { if(!(x)) { ZO_ERROR("Assertion Faild: {0}", __VA_ARGS__); __debugbreak();}}
	#define ZO_CORE_ASSERT(x, ...) { if(!(x)) { ZO_CORE_ERROR("Assertion Faild: {0}", __VA_ARGS__}; __debugbreak();}}
#else
	#define ZO_ASSERT(x, ...)
	#define ZO_CORE_ASSERT(x, ...)
#endif // ZO_ENABLE_ASSERSTS


#define BIT(x) (1 << x)