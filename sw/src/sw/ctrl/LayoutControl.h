#pragma once

#include <vector>

#include "sw/ctrl/ControlBase.h"
#include "sw/ctrl/ControlParrent.h"

namespace sw {

	class ControlBase;

	class LayoutControl : virtual public ControlBase,
						  virtual public ControlParrent {
	private:
		std::vector<ControlBase*> m_Children;

	protected:
		const std::vector<ControlBase*>& getChildren() const;

		virtual void onChildAdded(ControlBase* child) = 0;

	public:
		LayoutControl();
		virtual ~LayoutControl();

		void addChild(ControlBase* child);
	};

}

