#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw\Window.h"
#include "sw/controls/Control.h"
#include "sw/controls/ControlBase.h"

using namespace std;

using namespace sw;
using namespace util;
using namespace graph;
using namespace controls;

int main( void )
{
	app();

	Window* window = new Window(Size(640, 520), "My Window");
	Control* control = new Control(nullptr, Point(50, 50), Size(200, 100));
	control->Background = Colors::red;
	window->setContent((ControlBase*)control);
	window->redraw();

	app()->run();

	stopApplication();
	exit(EXIT_SUCCESS);
}

int WinMain() {
	main();
	return 0;
}