#pragma once

#include <map>

#include "sw/ctrl/ControlBase.h"
#include "sw/ctrl/ControlParrent.h"

namespace sw {

	class ControlBase;

	class LayoutControl : virtual public ControlBase,
						  virtual public ControlParrent {
	public:
		typedef std::map<ControlBase*, void*> T_ChildMap;
	private:
		T_ChildMap m_Children;

	protected:
		const T_ChildMap& getChildren() const;

		virtual void* onChildAdded(ControlBase* child) = 0;

	public:
		LayoutControl();
		virtual ~LayoutControl();

		void addChild(ControlBase* child);
	};

}

