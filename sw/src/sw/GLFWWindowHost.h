#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

#include "sw/util/Size.h"

#include "sw/Application.h"

namespace sw {

	class GLFWWindowHost {
	private:
		GLFWwindow* m_Handle;

		Size m_Size;
		std::string m_Title;

	public:
		GLFWWindowHost() = delete;
		GLFWWindowHost(const GLFWWindowHost& source) = delete;
		GLFWWindowHost(const Size& size, const std::string& title);
		virtual ~GLFWWindowHost();

		GLFWwindow* getHandle() const;

		Size getSize() const;
		void setSize(const Size& size);
		std::string getTitle() const;
		void setTitle(const std::string& title);

		bool shouldClose() const;
		void close();
		void makeContextCurrent() const;
		void swapBuffers() const;

	private:
		static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void glfwCloseCallback(GLFWwindow* window);
		static void glfwSizeCallback(GLFWwindow* window, int width, int height);
		static void glfwPositionCallback(GLFWwindow* window, int xpos, int ypos);
		static void glfwRefreshCallback(GLFWwindow* window);

		void keyPressedCallback(int key, int scancode, int action, int mods);
		void closeRequestedCallback();
		void sizeChangedCallback(int width, int height);
		void positionChangedCallback(int xpos, int ypos);
		void refreshCallback();

	public:
		virtual void onSizeChanged() = 0;
		virtual void onRender() = 0;
	};

}