#pragma once

#include "sw/util/Size.h"

#include "sw/ctrl/ControlBase.h"

namespace sw { namespace ctrl {

	class ContainerControl : public virtual ControlBase {
	public:
		ContainerControl();
		virtual ~ContainerControl();

		virtual util::Size getContainerArea(ControlBase* control) = 0;
	};

}}

