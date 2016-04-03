#pragma once

#include <cstdlib>
#ifdef _DEBUG
	#include <intrin.h>
#endif

#define byte unsigned char
#define uint unsigned int

#ifdef _DEBUG
	#define ASSERT(x) if(!(x)) { __debugbreak(); }
	#define FATAL(x, y) if(!(x)) { Application::fatalError(y); }
	#define WARN(x, y) if(x) { Logger::current().logWarning(y); }
	#define DEBUG_INFO(x) Logger::current().logInfo(x)
#else
	#define ASSERT(x)
	#define FATAL(x, y)
	#define WARN(x, y)
#endif

inline void pause() {
	system("pause");
}

#include "sw/Logger.h"