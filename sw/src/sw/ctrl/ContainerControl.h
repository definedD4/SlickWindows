#pragma once

#include "sw/util/Size.h"

#include "sw/ctrl/ControlBase.h"

namespace sw {

	class ControlParrent {
		virtual Size getContainerArea(ControlBase* control) = 0;
	};

}
