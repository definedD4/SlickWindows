#include "Control.h"

using namespace sw::util;

namespace sw { namespace controls {

	Control::Control(ContainerControl* parrent,
	                 const Point& position, const Size& size)
		: ControlBase(parrent, position, size) { }

	void Control::render() {
		getRenderBuffer()->clear(Background);
		getParrent()->render();
	}

	void Control::resize() {
		setPosition(Point(Margin().l, Margin().t));
		ContainerControl* parrent = getParrent();
		Size contArea = parrent->getContainerArea(this);
		contArea.w -= Margin().l + Margin().r;
		contArea.h -= Margin().t + Margin().b;
		setSize(contArea);
		redraw();
	}

	void Control::redraw() {
		render();
	}
}}

