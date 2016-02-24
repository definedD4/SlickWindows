#include "Window.h"

using namespace std;

using namespace sw;

namespace sw {

	Window::Window(Size size, std::string title) {
		m_Size = size;
		m_Title = title;

		m_Handle = glfwCreateWindow(m_Size.w, m_Size.h, m_Title.c_str(), NULL, NULL);

		if (!m_Handle) {
			Application::fatalError("Failed to open GLFW window.");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		APP->registerWindow(this);

		glfwMakeContextCurrent(m_Handle);

		glfwSetKeyCallback(m_Handle, Application::keyCallback);
		glfwSetWindowCloseCallback(m_Handle, Application::closeCallback);
		glfwSetWindowSizeCallback(m_Handle, Application::sizeCallback);
		glfwSetWindowPosCallback(m_Handle, Application::positionCallback);
		glfwSetWindowRefreshCallback(m_Handle, Application::refreshCallback);

		m_Renderer = new Renderer(this);

		GLenum err = glewInit();
		if (err != GLEW_OK) {
			Application::fatalError("GLEW init failed: \"" + string((char*)glewGetErrorString(err)) + "\".");
		}

		glClear(GL_COLOR_BUFFER_BIT);
	}


	Window::~Window() {
		destroyWindow();
	}

	void Window::setContent(ControlBase* content) {
		WARN(!content, "Setting window content to 0.")
		m_Root = new RootControl(this);
		m_Root->setContent(content);
		m_Root->resize();
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

	void Window::render() {
		glfwMakeContextCurrent(m_Handle);

		m_Root->render();

		glfwSwapBuffers(m_Handle);
	}

	void Window::c_keyPressed(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			closeWindow();
	}

	void Window::c_closeRequested() {
		glfwSetWindowShouldClose(m_Handle, GL_TRUE);
		destroyWindow();
		APP->deleteWindow(this);
	}

	void Window::c_sizeChanged(int width, int height) {
		m_Size.w = width;
		m_Size.h = height;

		makeContextCurrent();

		glViewport(0, 0, width, height);

		m_Root->resize();
	}

	void Window::c_positionChanged(int xpos, int ypos) { }

	void Window::c_refresh() {
		render();
	}
}

