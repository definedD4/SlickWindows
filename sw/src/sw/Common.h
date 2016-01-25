#pragma once

#include <cstdlib>
#include <string>

#define byte unsigned char
#define uint unsigned int

#ifdef _DEBUG
	#define ASSERT(x) if(!(x)) { Application::fatalError("Assertation failed"); }
	#define ASSERT_MSG(x, y) if(!(x)) { Application::fatalError(y); }
	#define WARN(x, y) if(x) { logger()->logWarning(y); }
#else
	#define ASSERT(x)
	#define ASSERT_MSG(x, y)
	#define WARN(x, y)
#endif

inline void pause() {
	system("pause");
}

//Forward declarations
namespace sw {
	
	class Application;
	class Window;
	class Dispatcher;
	class Task;
	class Logger;
	namespace graph {
		class Bitmap;
	}
	namespace controls {
		//class ControlBase;
		class ContainerControl;
		class RootControl;
	}

}