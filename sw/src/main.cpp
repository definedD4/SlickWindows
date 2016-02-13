#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw/ctrl/RootControl.h"

#include "sw/ctrl/Test_Rect.h"

using namespace std;

using namespace sw;
using namespace util;
using namespace graph;
using namespace ctrl;

int main( void )
{
	startApplication();

	Window* window = new Window(Size(640, 520), "My Window");

	Test_Rect* rect = new Test_Rect();
	rect->Fill = Colors::white;
	window->setContent(rect);

	window->redraw();

	APP->run();

	stopApplication();
	exit(EXIT_SUCCESS);
}

int WinMain() {
	main();
	return 0;
}