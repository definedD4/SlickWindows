#pragma once
#include "ControlBase.h"
#include "../Property.h"
#include  "../util/Thickness.h"
#include "../util/Dimension.h"

namespace sw { 

	enum class HorizontalLayout {
		Left,
		Right,
		Center,
		Stretch
	};

	enum class VerticalLayout {
		Up,
		Down,
		Center,
		Stretch
	};

	class LayoutControl : public virtual ControlBase {
	public:
		LayoutControl();
		virtual ~LayoutControl();

		Property<Dimension> Width;
		Property<Dimension> Height;
		Property<Thickness> Margin;
		Property<HorizontalLayout> HorizontalLayout;
		Property<VerticalLayout> VerticalLayout;

		virtual void resize();
	};

}

