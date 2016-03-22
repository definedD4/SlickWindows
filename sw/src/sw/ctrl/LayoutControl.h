#pragma once
#include "ControlBase.h"
#include "../Property.h"
#include  "../util/Thickness.h"
#include "../util/Dimension.h"


	class LayoutControl_ : public virtual ControlBase {
	public:
		LayoutControl_();
		virtual ~LayoutControl_();

		Property<Dimension> Width;
		Property<Dimension> Height;
		Property<Thickness> Margin;
		Property<HorizontalLayout> HorizontalLayout;
		Property<VerticalLayout> VerticalLayout;

		virtual void resize();
	};

}

