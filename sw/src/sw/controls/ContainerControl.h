#pragma once

#include "ControlBase.h"
#include "../util/Size.h"

namespace sw { namespace controls {

	class ContainerControl : public virtual ControlBase {
	public:
		virtual ~ContainerControl() {}
		virtual util::Size getContainerArea(ControlBase* control) = 0;
	};

} }