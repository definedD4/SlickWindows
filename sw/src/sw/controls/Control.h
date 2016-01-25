#pragma once
#include "ControlBase.h"
#include "../Property.h"
#include "../util/Thickness.h"
#include "ContainerControl.h"

namespace sw { namespace controls {

	class Control : public virtual ControlBase {
	public:
		Control(ContainerControl* parrent,
		        const sw::util::Point& position, const sw::util::Size& size);

		Property<util::Thikness> Margin;
		Property<util::Color> Background;

		void render() override;
		void resize() override;
		void redraw() override;
	};

}}

