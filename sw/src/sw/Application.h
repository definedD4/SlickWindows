#pragma once

#include <vector>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Dispatcher.h"

namespace sw {

	inline Application* app();

	class Application {
	public:
		static Application* current() {
			static Application* app;
			if (!app) {
				app = new Application();
			}
			return app;
		}

	private:
		bool m_Running;

		std::map<GLFWwindow*, Window*> m_Windows;

		Dispatcher* m_Dispatcher;

		Application();
		Application(Application const&) = delete;
		void operator=(Application const&) = delete;

		void initGL();
		static void errorCallback(int error, const char* description);

	public:
		~Application();

		void run();
		void stop();

		static void error(std::string description);

		Dispatcher* getDispatcher() const {
			return m_Dispatcher;
		}

		void registerWindow(Window* window);
		void deleteWindow(Window* window);
		Window* getWindow(GLFWwindow* window);

		static void keyCallback(GLFWwindow* window,
		                        int key, int scancode, int action, int mods);
		static void closeCallback(GLFWwindow* window);
		static void sizeCallback(GLFWwindow* window, int width, int height);
		static void positionCallback(GLFWwindow* window, int xpos, int ypos);
		static void refreshCallback(GLFWwindow* window);
	};

	inline Application* app() {
		return Application::current();
	}

}

