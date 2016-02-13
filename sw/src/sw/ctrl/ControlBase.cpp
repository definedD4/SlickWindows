#include "ControlBase.h"

namespace sw { namespace ctrl {

	ControlBase::ControlBase() {}

	ControlBase::~ControlBase() {}

	void ControlBase::render() {
		m_Parrent->render();
	}

	void ControlBase::resize() {
		ResizeEvent.raiseEvent({ m_Size });
		render();
	}

} }