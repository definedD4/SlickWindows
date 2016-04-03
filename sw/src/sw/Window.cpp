#include "Window.h"

using namespace std;

using namespace sw;

namespace sw {

	Window::Window(const Size& size, const std::string& title) :
			GLFWWindowHost(size, title) {
		m_Renderer = new Renderer(this);
	}


	Window::~Window() {
		delete m_Renderer;
		delete m_Root;
	}

	Renderer* Window::getRenderer() const {
		return m_Renderer;
	}

	void Window::setContent(ControlBase* content) {
		WARN(!content, "Setting window content to 0.")
		m_Root = new RootControl(this);
		m_Root->setContent(content);
		m_Root->resize();
		onRender();
	}

	void Window::onRender() {
		makeContextCurrent();

		m_Root->render();

		swapBuffers();
	}


	void Window::onSizeChanged() {
		m_Root->resize();
		makeContextCurrent();
		m_Root->render();
	}
}

