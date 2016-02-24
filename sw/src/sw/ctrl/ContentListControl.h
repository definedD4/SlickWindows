#pragma once

#include <vector>

#include "ControlBase.h"

namespace sw {

	class ControlBase;

	class ContentListControl : virtual public ContainerControl {
	private:
		std::vector<ControlBase*> m_Children;

	protected:
		const std::vector<ControlBase*>& getChildren() const {
			return m_Children;
		}

		void addToChildren(ControlBase* child) {
			child->setParrent(static_cast<ContainerControl*>(this));
			m_Children.push_back(child);
		}

		void setChildPosition(ControlBase* child, Point pos) {
			child->setPosition(pos);
		}

	public:
		ContentListControl();
		virtual ~ContentListControl();
	};

}

