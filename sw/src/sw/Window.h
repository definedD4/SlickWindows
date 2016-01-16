#pragma once

#include <iostream>
#include <string>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util/Size.h"
#include "graph/Bitmap.h"
#include "Application.h"

using namespace sw;
using namespace graph;

namespace sw {
	namespace wnd {

		class Window
		{
		private:
			GLFWwindow* m_Handle;

			Size m_Size;
			std::string m_Title;

			Bitmap* m_Buffer;

		public:
			Window(Size size, std::string title);
			~Window();

			GLFWwindow* getHandle() const { return m_Handle; }
			Size getSize() const { return m_Size; }
			void setSize(Size size) { m_Size = size; glfwSetWindowSize(m_Handle, m_Size.w, m_Size.h); }
			std::string getTitle() const { return m_Title; }
			void setTitle(std::string title) { m_Title = title; glfwSetWindowTitle(m_Handle, m_Title.c_str()); }
			Bitmap* getBuffer() const { return m_Buffer; }

			void destroyWindow();
			bool windowShoudClose() const;
			void closeWindow();
			void redraw();

			void c_keyPressed(int key, int scancode, int action, int mods);
			void c_closeRequested();
			void c_sizeChanged(int width, int height);
			void c_positionChanged(int xpos, int ypos);
			void c_refresh();
		};



	}

}

