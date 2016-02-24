#pragma once

#include "sw/util/Size.h"

#include "sw/ctrl/ControlBase.h"

namespace sw {

	class ContainerControl : public virtual ControlBase {
	public:
		ContainerControl();
		virtual ~ContainerControl();

		virtual Size getContainerArea(ControlBase* control) = 0;
	};

}
