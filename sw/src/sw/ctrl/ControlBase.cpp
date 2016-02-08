#include "ControlBase.h"

namespace sw { namespace ctrl {

	ControlBase::ControlBase() {}

	ControlBase::~ControlBase() {}

	void ControlBase::render() {
		m_RenderRequested = false;
	}

	void ControlBase::redraw() {
		m_RedrawRequested = false;
		m_RenderRequested = false;
	}
} }