#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw/ctrl/RootControl.h"

#include "sw/ctrl/Test_Rect.h"
#include "sw/ctrl/Grid.h"
#include "sw/AttachedProperty.h"

using namespace std;

using namespace sw;

int main( void )
{
	startApplication();

	Window* window = new Window(Size(640, 520), "My Window");


	Grid* grid = new Grid();
	grid->setGrid(vector<int>{2, 1}, vector<int>{1});
	grid->Margin = Thickness(5, 10, 5, 10);

	Test_Rect* rect1 = new Test_Rect();
	rect1->Fill = Colors::green;
	rect1->setProperty(&Grid::ColumnProperty, 0);

	Test_Rect* rect2 = new Test_Rect();
	rect2->Fill = Colors::red;
	rect1->setProperty(&Grid::ColumnProperty, 1);

	grid->addChild(rect1);
	grid->addChild(rect2);

	window->setContent(grid);

	window->render();

	APP->run();

	stopApplication();
	exit(EXIT_SUCCESS);
}

int WinMain() {
	main();
	return 0;
}