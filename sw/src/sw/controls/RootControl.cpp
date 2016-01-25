#include "RootControl.h"

using namespace sw::util;

namespace sw { namespace controls {

	RootControl::RootControl(Window* owner, ControlBase* child)
		: ControlBase(nullptr, Point(0, 0), Size(0, 0)),
		  m_Owner(owner), m_Child(child) {
		m_Child->setParrent(this);

		setSize(m_Owner->getSize());
	}

	RootControl::~RootControl() {
		delete m_Child;
	}

	void RootControl::render() {
		 m_Child->drawOn(m_Owner->getBuffer());
		 m_Owner->render();
	}

	void RootControl::resize() {
		setSize(m_Owner->getSize());
		m_Child->resize();
		render();
	}

	void RootControl::redraw() {
		m_Child->redraw();
	}

	util::Size RootControl::getContainerArea(ControlBase* control) {
		ASSERT(m_Child == control)
		return getSize();
	}
}}

