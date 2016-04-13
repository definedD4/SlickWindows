#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw/ctrl/RootControl.h"

#include "sw/ctrl/Test_Rect.h"
#include "sw/AttachedProperty.h"
#include "sw/ctrl/StackLayout.h"

using namespace std;

using namespace sw;

int main( void )
{
	Window* window = new Window(Size(640, 520), "My Window");

	StackLayout* sl = new StackLayout();

	Test_Rect* rect1 = new Test_Rect();
	rect1->Fill = Colors::green;
	rect1->Height = Dimension::fromInt(400);
	rect1->VerticalLayout = VerticalLayout::Center;
	rect1->HorizontalLayout = HorizontalLayout::Center;

	sl->addChild(rect1);

	Test_Rect* rect2 = new Test_Rect();
	rect2->Fill = Colors::red;
	rect2->Width = Dimension::fromInt(100);
	rect2->Height = Dimension::fromInt(250);

	sl->addChild(rect2);

	window->setContent(sl);

	Application::current().run();
	return 0;
}

int WinMain() {
	main();
	return 0;
}