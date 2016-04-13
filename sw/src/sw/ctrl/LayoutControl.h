#pragma once

#include <vector>

#include "sw/ctrl/ControlBase.h"
#include "sw/ctrl/ControlParrent.h"

namespace sw {

	class ControlBase;

	class LayoutControl : virtual public ControlBase,
						  virtual public ControlParrent {
	protected:
		struct child_data {
			ControlBase* childPtr;
			void* customData;
		};

	private:
		std::vector<child_data> m_Children;

	protected:
		const std::vector<child_data>& getChildren() const;

		virtual void* onChildAdded(ControlBase* child) = 0;

	public:
		LayoutControl();
		virtual ~LayoutControl();

		void addChild(ControlBase* child);

		Renderer* getRenderer() const override;
	};

}

