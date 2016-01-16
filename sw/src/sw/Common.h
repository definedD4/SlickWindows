#pragma once

#include <cstdlib>
#include <string>

#define byte unsigned char
#define uint unsigned int

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

}