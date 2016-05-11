#pragma once

#include <vector>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sw/GLFWWindowHost.h"
#include "sw/fmwk/Dispatcher.h"
#include "Logger.h"

namespace sw {

	class GLFWWindowHost;

	class Application {
	private:
		static Application s_Instance;

	public:
		static Application& current() {
			return s_Instance;
		}

	private:
		bool m_Running;
		int m_WindowCount = 0;

		Dispatcher* m_Dispatcher;

		Application();

	public:
		Application(Application const&) = delete;
		void operator=(Application const&) = delete;
		~Application();

	private:
		static void errorCallback(int error, const char* description);

		void addWindow(GLFWWindowHost *window);
		void removeWindow(GLFWWindowHost *window);

	public:
		void run();

		static void fatalError(const std::string& description);

		Dispatcher* getDispatcher() const {
			return m_Dispatcher;
		}

		friend class GLFWWindowHost;
	};

}

