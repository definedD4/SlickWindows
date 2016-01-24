#include "Application.h"

using namespace std;

namespace sw {

	Application* Application::s_Instance = nullptr;

	void stopApplication() {
		app()->stop();
		delete Application::s_Instance;
		destroyLogger();
	}

	Application::Application() {
		initGL();

		m_Dispatcher = new Dispatcher();

		m_Running = true;
	}


	void Application::initGL() {
		glfwSetErrorCallback(errorCallback);

		if (!glfwInit()) {
			fatalError("GLEW init error.");
		}
	}

	void Application::errorCallback(int error, const char* description) {
		fatalError("ERROR: GLFW error #" + to_string(error) + ": \"" + description + "\".");
	}

	Application::~Application() {
		stop();
	}

	void Application::registerWindow(Window* window) {
		m_Windows[window->getHandle()] = window;
	}

	void Application::deleteWindow(Window* window) {
		m_Windows.erase(window->getHandle());
		if (m_Windows.size() == 0) {
			stop();
		}
	}

	Window* Application::getWindow(GLFWwindow* window) {
		return m_Windows[window];
	}

	void Application::stop() {
		if (!m_Running)
			return;

		m_Running = false;
		glfwPostEmptyEvent();
		if (m_Windows.size() > 0) {
			for (auto it = m_Windows.begin(); it != m_Windows.end(); ++it) {
				it->second->destroyWindow();
			}
		}
	}

	void Application::fatalError(string description) {
		logger()->logFatal(description);
		pause();
		exit(EXIT_FAILURE);
		
	}

	void Application::run() {
		while (m_Running) {
			glfwPollEvents();
			if (m_Running) {
				if (m_Dispatcher->tasksScheduled() > 0) {
					m_Dispatcher->process(1);
				} else {
					glfwWaitEvents();
				}
			}
		}
		glfwTerminate();
	}

	void Application::keyCallback(GLFWwindow* window,
	                              int key, int scancode, int action, int mods) {
		Window* wnd = current()->getWindow(window);
		if (wnd) {
			wnd->c_keyPressed(key, scancode, action, mods);
		}
	}

	void Application::closeCallback(GLFWwindow* window) {
		Window* wnd = app()->getWindow(window);
		if (wnd) {
			wnd->c_closeRequested();
		}
	}

	void Application::sizeCallback(GLFWwindow* window, int width, int height) {
		Window* wnd = app()->getWindow(window);
		if (wnd) {
			wnd->c_sizeChanged(width, height);
		}
	}


	void Application::positionCallback(GLFWwindow* window, int xpos, int ypos) {
		Window* wnd = app()->getWindow(window);
		if (wnd) {
			wnd->c_positionChanged(xpos, ypos);
		}
	}

	void Application::refreshCallback(GLFWwindow* window) {
		Window* wnd = app()->getWindow(window);
		if (wnd) {
			wnd->c_refresh();
		}
	}
}

