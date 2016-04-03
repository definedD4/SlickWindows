#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw/ctrl/RootControl.h"

#include "sw/ctrl/Test_Rect.h"
#include "sw/AttachedProperty.h"

using namespace std;

using namespace sw;

int main( void )
{
	Window* window = new Window(Size(640, 520), "My Window");

	Test_Rect* rect = new Test_Rect();
	rect->Fill = Colors::green;
	rect->Height = Dimension::fromInt(400);
	rect->VerticalLayout = VerticalLayout::Center;
	rect->HorizontalLayout = HorizontalLayout::Center;

	window->setContent(rect);

	Application::current().run();
	return 0;
}

int WinMain() {
	main();
	return 0;
}