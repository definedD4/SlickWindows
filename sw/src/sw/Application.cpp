#include "Application.h"

using namespace std;

namespace sw {

	Application Application::s_Instance;

	Application::Application() {
		glfwSetErrorCallback(errorCallback);

		if (!glfwInit()) {
			fatalError("GLEW init error.");
		}

		m_Dispatcher = new Dispatcher();

		m_Running = true;
	}

	void Application::errorCallback(int error, const char* description) {
		fatalError("ERROR: GLFW error #" + to_string(error) + ": \"" + description + "\".");
	}

	void Application::addWindow(GLFWWindowHost* window) {
		m_WindowCount++;
	}

	void Application::removeWindow(GLFWWindowHost* window) {
		m_WindowCount--;
		if(m_WindowCount == 0) {
			m_Running = false;
			glfwPostEmptyEvent();
		}
	}

	Application::~Application() {
		glfwTerminate();
	}

	void Application::fatalError(const string& description) {
		Logger::current().logFatal(description);
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
}

