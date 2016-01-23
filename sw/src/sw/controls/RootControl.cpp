#include "RootControl.h"

using namespace sw::util;

namespace sw { namespace controls {

	RootControl::RootControl(Window* owner, ControlBase* child)
		: ControlBase(nullptr, Point(0, 0), Size(0, 0)),
		  m_Owner(owner), m_Child(child) {}

	void RootControl::render() {
		 m_Child->drawOn(m_Owner->getBuffer());
	}

	void RootControl::resize() {}
}}

