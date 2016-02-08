#pragma once
#include "ControlBase.h"

namespace sw { namespace ctrl {

	class ContainerControl : public virtual ControlBase {
	public:
		ContainerControl();
		virtual ~ContainerControl();

		virtual util::Size getContainerArea(ControlBase* control) = 0;
	};

}}

