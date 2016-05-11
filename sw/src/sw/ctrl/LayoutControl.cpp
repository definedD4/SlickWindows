#include "LayoutControl.h"

namespace sw {
	LayoutControl::LayoutControl()
		: ControlParrent(), ControlBase() {
	}

	LayoutControl::~LayoutControl() {
		for (auto item : m_Children) {
			delete item.first;
			delete item.second;
		}
	}

	const LayoutControl::T_ChildMap& LayoutControl::getChildren() const {
		return m_Children;
	}

	void LayoutControl::addChild(ControlBase * child) {
		child->setParrent(static_cast<ControlParrent*>(this));
		void* custom = onChildAdded(child);
		m_Children[child] = custom;
	}

	//Renderer* LayoutControl::getRenderer() const {
	//	return ControlBase::getRenderer();
	//}
}
