#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw\Window.h"

using namespace std;

using namespace sw;
using namespace util;
using namespace graph;
using namespace controls;

int main( void )
{
	app();

	Window* window = new Window(Size(640, 520), "Window 1");
	window->redraw();

	app()->run();

	stopApplication();
	exit(EXIT_SUCCESS);
};