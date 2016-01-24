#include "Control.h"

using namespace sw::util;

namespace sw { namespace controls {

	Control::Control(ControlBase* parrent,
	                 const Point& position, const Size& size)
		: ControlBase(parrent, position, size) { }

	void Control::render() {
		getRenderBuffer()->clear(Background);
		getParrent()->render();
	}

	void Control::resize() {}

	void Control::redraw() {
		render();
	}
}}

