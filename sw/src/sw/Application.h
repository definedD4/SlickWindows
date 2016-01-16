#pragma once

#include <vector>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Dispatcher.h"
#include "Logger.h"

namespace sw {

	inline Application* app();
	void stopApplication();

	class Application {
	private:
		static Application* s_Instance;
	public:
		static Application* current() {
			if (!s_Instance) {
				s_Instance = new Application();
			}
			return s_Instance;
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

		static void fatalError(std::string description);

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

		friend void stopApplication();
	};

	inline Application* app() {
		return Application::current();
	}

}

