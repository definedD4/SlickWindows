#include "RootControl.h"

namespace sw {

	RootControl::RootControl(Window* owner) : ControlParrent(), m_Owner(owner) { }

	RootControl::~RootControl() {
		delete m_Content;
	}

	Size RootControl::getContainerArea(ControlBase* control) const {
		ASSERT(m_Owner != nullptr)
		ASSERT(control == m_Content)
		return m_Owner->getSize();
	}

	//Point RootControl::transformToWindowSpace(Point point, const ControlBase* const control) const {
	//	return point;
	//}
	
	Renderer RootControl::getRenderer(ControlBase* control) const {
		ASSERT(control == m_Content)
		ASSERT(m_Owner != nullptr)
		return Renderer(m_Owner->getRenderTarget());
	}

	void RootControl::setContent(ControlBase* content) {
		if (m_Content != nullptr) {
			delete m_Content;
		}
		ASSERT(content != nullptr)
		m_Content = content;
		m_Content->setParrent(static_cast<ControlParrent*>(this));
	}

	void RootControl::render() {
		m_Content->render();
	}

	void RootControl::resize() {
		m_Content->resize();
	}

}

