#include "Window.h"

using namespace std;

using namespace sw;
using namespace graph;

namespace sw {


	Window::Window(Size size, std::string title) {
		m_Size = size;
		m_Title = title;

		m_Handle = glfwCreateWindow(m_Size.w, m_Size.h, m_Title.c_str(), NULL, NULL);

		if (!m_Handle) {
			std::cout << "Failed to open GLFW window.\n";
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		app()->registerWindow(this);

		glfwMakeContextCurrent(m_Handle);

		glfwSetKeyCallback(m_Handle, Application::keyCallback);
		glfwSetWindowCloseCallback(m_Handle, Application::closeCallback);
		glfwSetWindowSizeCallback(m_Handle, Application::sizeCallback);
		glfwSetWindowPosCallback(m_Handle, Application::positionCallback);
		glfwSetWindowRefreshCallback(m_Handle, Application::refreshCallback);

		m_Buffer = new Bitmap(m_Size);

		GLenum err = glewInit();
		if (err != GLEW_OK) {
			std::cout << "ERROR: glewInit failed: \"" << glewGetErrorString(err) << "\".\n";
			system("pause");
			exit(EXIT_FAILURE);
		}

		glClear(GL_COLOR_BUFFER_BIT);
	}


	Window::~Window() {
		destroyWindow();
	}

	void Window::destroyWindow() {
		glfwDestroyWindow(m_Handle);
	}

	bool Window::windowShoudClose() const {
		return glfwWindowShouldClose(m_Handle) == GL_TRUE;
	}

	void Window::closeWindow() {
		glfwSetWindowShouldClose(m_Handle, GL_TRUE);
	}

	void Window::redraw() {
		glfwMakeContextCurrent(m_Handle);
		glRasterPos2i(-1, -1);

		Size sz = m_Buffer->getSize();
		glDrawPixels(sz.w, sz.h, GL_RGBA, GL_UNSIGNED_BYTE, m_Buffer->getPixels());

		glfwSwapBuffers(m_Handle);
	}

	void Window::c_keyPressed(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			closeWindow();
	}

	void Window::c_closeRequested() {
		glfwSetWindowShouldClose(m_Handle, GL_TRUE);
		app()->deleteWindow(this);
		destroyWindow();
	}

	void Window::c_sizeChanged(int width, int height) {
		m_Size.w = width;
		m_Size.h = height;

		delete m_Buffer;
		m_Buffer = new Bitmap(m_Size);

		redraw();
	}

	void Window::c_positionChanged(int xpos, int ypos) { }

	void Window::c_refresh() {
		redraw();
	}
}

