#include "Application.h"

namespace sw {
	namespace wnd {

		Application::Application(){
			initGL();

			m_Dispatcher = new Dispatcher();

			m_Running = true;
		}


		void Application::initGL() {
			glfwSetErrorCallback(errorCallback);

			if (!glfwInit())
			{
				error("ERROR: glfwInit failed.");
			}
		}

		void Application::errorCallback(int error, const char* description) {
			std::cout << "ERROR: GLFW error #" << error << ": \"" << description << "\".\n";
			system("pause");
			exit(EXIT_FAILURE);
		}

		Application::~Application(){
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
			m_Running = false;
			glfwPostEmptyEvent();
			if(m_Windows.size() > 0) {
				for (auto it = m_Windows.begin(); it != m_Windows.end(); ++it) {
					it->second->destroyWindow();
				}
			}
			glfwTerminate();
		}

		void Application::error(std::string description) {
			std::cout << "ERROR: " << description << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}

		void Application::run() {
			while (m_Running) {
				glfwPollEvents();
				m_Dispatcher->process(1);
			}
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
			if(wnd) {
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
}