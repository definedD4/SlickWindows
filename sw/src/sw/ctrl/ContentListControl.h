#pragma once

#include <vector>

#include "ContainerControl.h"

namespace sw { namespace ctrl {

	class ContentListControl : ContainerControl {
	protected:

		virtual std::vector<ControlBase*>* getItems() = 0;

	public:
		ContentListControl();
		virtual ~ContentListControl();


		virtual void render() = 0;
		virtual void redraw();
	};

}}

