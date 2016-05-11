#include "Window.h"

#include "sw/graph/WindowRenderTarget.h"

using namespace std;

using namespace sw;

namespace sw {

	Window::Window(const Size& size, const std::string& title) :
			GLFWWindowHost(size, title) {
	}


	Window::~Window() {
		delete m_Root;
	}

	RenderTarget* Window::getRenderTarget() const {
		return new WindowRenderTarget(this);
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

