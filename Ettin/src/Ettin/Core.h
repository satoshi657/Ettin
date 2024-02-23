#pragma once

#ifdef ET_PLATFORM_WINDOWS
	#ifdef ET_BUILD_DLL
		#define ETTIN_API __declspec(dllexport)
	#else
		#define ETTIN_API __declspec(dllimport)
	#endif
#else
	#error ETTIN only support windows!
#endif

