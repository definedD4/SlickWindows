#pragma once

#include <vector>

#include "ContainerControl.h"

namespace sw { namespace ctrl {

	class ControlBase;

	class ContentListControl : virtual public ContainerControl {
	private:
		std::vector<ControlBase*> m_Children;

	protected:
		std::vector<ControlBase*> getChildren() const {
			return m_Children;
		}

		void addToChildren(ControlBase* child) {
			child->setParrent(static_cast<ContainerControl*>(this));
			m_Children.push_back(child);
		}

		void setChildPosition(ControlBase* child, util::Point pos) {
			child->setPosition(pos);
		}

	public:
		ContentListControl();
		virtual ~ContentListControl();
	};

}}

