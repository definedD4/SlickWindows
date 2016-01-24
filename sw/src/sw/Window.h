#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Common.h"
#include "Application.h"
#include "util/Size.h"
#include "graph/Bitmap.h"
#include "controls/RootControl.h"

namespace sw {

	class Window {
	private:
		GLFWwindow* m_Handle;

		util::Size m_Size;
		std::string m_Title;

		graph::Bitmap* m_Buffer;

		controls::RootControl* m_Root;

	public:
		Window(util::Size size, std::string title);
		~Window();

		GLFWwindow* getHandle() const {
			return m_Handle;
		}

		util::Size getSize() const {
			return m_Size;
		}

		void setSize(util::Size size) {
			m_Size = size;
			glfwSetWindowSize(m_Handle, m_Size.w, m_Size.h);
		}

		std::string getTitle() const {
			return m_Title;
		}

		void setTitle(const std::string& title) {
			m_Title = title;
			glfwSetWindowTitle(m_Handle, m_Title.c_str());
		}

		graph::Bitmap* getBuffer() const {
			return m_Buffer;
		}

		void setContent(controls::ControlBase* content);

		void destroyWindow();
		bool windowShoudClose() const;
		void closeWindow();
		void render();
		void redraw();

		void c_keyPressed(int key, int scancode, int action, int mods);
		void c_closeRequested();
		void c_sizeChanged(int width, int height);
		void c_positionChanged(int xpos, int ypos);
		void c_refresh();
	};


}

