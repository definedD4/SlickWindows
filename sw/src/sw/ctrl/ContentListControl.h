#pragma once

#include <vector>

#include "ContainerControl.h"

namespace sw { namespace ctrl {

	class ControlBase;

	class ContentListControl : ContainerControl {
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

	public:
		ContentListControl();
		virtual ~ContentListControl();


		virtual void render() = 0;
		virtual void redraw();
	};

}}

