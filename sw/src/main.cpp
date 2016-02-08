#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw/controls/ContainerControl.h"
#include "sw/controls/ControlBase.h"
#include "sw/controls/Control.h"
#include "sw\Window.h"

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
	control->Margin = Thickness(20, 20, 20, 20);
	window->setContent(static_cast<ControlBase*>(control));
	window->redraw();

	app()->run();

	stopApplication();
	exit(EXIT_SUCCESS);
}

int WinMain() {
	main();
	return 0;
}