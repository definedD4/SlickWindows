#pragma once

#include <cstdlib>
#include <string>

#define byte unsigned char
#define uint unsigned int

#ifdef _DEBUG
	#define ASSERT(x, y) if(!(x)) { Application::fatalError(y); }
	#define WARN(x, y) if(x) { logger()->logWarning(y); }
#else
	#define ASSERT(x, y)
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
		class LayoutControl;
		class RootControl;
		class VisualControl;
	}

}