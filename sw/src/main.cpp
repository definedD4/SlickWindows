#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sw\Window.h"
#include "sw/Property.h"

using namespace std;
using namespace sw;
using namespace wnd;

void pause() {
	system("pause");
}

class A {
public:
	Property<int> Prop = 2;

};

int main( void )
{
	A a;
	cout << a.Prop() << endl;
	a.Prop = 3;
	int b = a.Prop;
	cout << b << endl;
	/*app();

	Window* window = new Window(Size(640, 520), "Window 1");

	app()->run();

	app()->stop();*/
	
	exit(EXIT_SUCCESS);
};