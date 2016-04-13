#include "LayoutControl.h"

namespace sw {
	LayoutControl::LayoutControl()
		: ControlParrent(), ControlBase() {
	}

	LayoutControl::~LayoutControl() {
		for (LayoutControl::child_data item : m_Children) {
			delete item.childPtr;
			delete item.customData;
		}
	}

	const std::vector<LayoutControl::child_data>& LayoutControl::getChildren() const {
		return m_Children;
	}

	void LayoutControl::addChild(ControlBase * child) {
		child->setParrent(static_cast<ControlParrent*>(this));
		void* custom = onChildAdded(child);
		m_Children.push_back({ child, custom });
	}

	Renderer* LayoutControl::getRenderer() const {
		return ControlBase::getRenderer();
	}
}
