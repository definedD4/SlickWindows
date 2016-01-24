#pragma once
#include "ControlBase.h"
#include "../Property.h"

namespace sw { namespace controls {

	class Control : virtual sw::controls::ControlBase {
	public:
		Control(ControlBase* parrent,
		        const sw::util::Point& position, const sw::util::Size& size);

		Property<util::Color> Background;


		void render() override;
		void resize() override;
		void redraw() override;
	};

}}

