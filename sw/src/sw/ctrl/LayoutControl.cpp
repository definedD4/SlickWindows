#include "LayoutControl.h"

namespace sw {
	LayoutControl::LayoutControl()
		: ControlParrent(), ControlBase() {
	}

	LayoutControl::~LayoutControl() {
		for (ControlBase* item : m_Children) {
			delete item;
		}
	}

	const std::vector<ControlBase*>& LayoutControl::getChildren() const {
		return m_Children;
	}

	void LayoutControl::addChild(ControlBase * child) {
		child->setParrent(static_cast<ControlParrent*>(this));
		m_Children.push_back(child);
		onChildAdded(child);
	}
}