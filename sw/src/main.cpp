#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw\Window.h"

using namespace std;
using namespace sw;
using namespace wnd;

void pause() {
	system("pause");
}

int main( void )
{
	app();

	Window* window = new Window(Size(640, 520), "Window 1");

	app()->run();

	app()->stop();
	exit(EXIT_SUCCESS);
};