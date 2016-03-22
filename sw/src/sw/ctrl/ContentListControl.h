#pragma once

#include <vector>

#include "ControlBase.h"
#include "ControlParrent.h"

namespace sw {

	class ControlBase;

	class LayoutControl : virtual public ControlBase,
							   virtual public ControlParrent {
	private:
		std::vector<ControlBase*> m_Children;

	protected:
		const std::vector<ControlBase*>& getChildren() const {
			return m_Children;
		}

		void addChild(ControlBase* child) {
			child->setParrent(static_cast<ControlParrent*>(this));
			m_Children.push_back(child);
		}

		void setChildPosition(ControlBase* child, Point pos) {
			child->setPosition(pos);
		}

	public:
		LayoutControl();
		virtual ~LayoutControl();
	};

}

