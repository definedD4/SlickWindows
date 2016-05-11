#include "WindowRenderTarget.h"

namespace sw {

	WindowRenderTarget::WindowRenderTarget(const Window* window) : m_Window(window)
	{
	}


	WindowRenderTarget::~WindowRenderTarget()
	{
	}


	void WindowRenderTarget::beginRender() {
		m_Window->makeContextCurrent();
	}

	void WindowRenderTarget::endRender() {}


	Size WindowRenderTarget::getSize() const {
		return m_Window->getSize();
	}
}
