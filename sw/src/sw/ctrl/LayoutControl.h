#pragma once
#include "ControlBase.h"
#include "../Property.h"
#include  "../util/Thickness.h"
#include "../util/Dimension.h"

namespace sw { namespace ctrl {

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

		Property<util::Dimension> Width;
		Property<util::Dimension> Height;
		Property<util::Thickness> Margin;
		Property<HorizontalLayout> HorizontalLayout;
		Property<VerticalLayout> VerticalLayout;

		virtual void resize();
	};

}}

