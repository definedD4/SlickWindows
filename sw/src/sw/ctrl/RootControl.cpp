#include "RootControl.h"

namespace sw {
	namespace ctrl {

		using namespace util;

		RootControl::RootControl(Window* owner) : ContainerControl(), m_Owner(owner) {
		}

		RootControl::~RootControl() {
			delete m_Content;
		}

		Renderer* RootControl::getRenderer() const {
			return m_Owner->getRenderer();
		}

		util::Size RootControl::getContainerArea(ControlBase* control) {
			ASSERT(m_Owner != nullptr)
			ASSERT(control == m_Content)
			return m_Owner->getSize();
		}

		void RootControl::setContent(ControlBase* content) {
			if (m_Content != nullptr) {
				delete m_Content;
			}
			ASSERT(content != nullptr)
			m_Content = content;
			m_Content->setParrent(static_cast<ContainerControl*>(this));
		}

		void RootControl::render() {
			m_Content->render();
		}

		void RootControl::resize() {
			setSize(m_Owner->getSize());
			m_Content->resize();
		}

	}
}