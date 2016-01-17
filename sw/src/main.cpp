#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw\Window.h"
#include "sw/controls/LayoutControl.h"
#include "sw/controls/VisualControl.h"

using namespace std;

using namespace sw;
using namespace util;
using namespace graph;
using namespace controls;

int main( void )
{
	app();

	Window* window = new Window(Size(640, 520), "Window 1");
	window->setChild((LayoutControl*)new VisualControl(
		Size(200, 100), Point(50, 50), Color(255, 0, 0, 255)));
	window->redraw();

	app()->run();

	stopApplication();
	exit(EXIT_SUCCESS);
};