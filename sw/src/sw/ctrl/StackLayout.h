#pragma once

#include "sw/util/Math.h"

#include "sw/ctrl/LayoutControl.h"

namespace sw {

	class StackLayout :
		public virtual LayoutControl
	{
	private:
		struct child_info {
			int offset;
			Size container;
		};

		int m_InsertOffset = 0;
		int m_MaxElemWidth = 0;

	public:
		StackLayout();
		virtual ~StackLayout();

		virtual void* onChildAdded(ControlBase* child) override;
		virtual Size getContainerArea(ControlBase* control) const override;
		//virtual Point transformToWindowSpace(Point point, const ControlBase* const control) const override;


		virtual Renderer getRenderer(ControlBase* control);

		virtual void resize() override;
		void render() override;
	};

}

