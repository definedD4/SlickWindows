#pragma once

#include "../Logger.h"

#include "ControlBase.h"

namespace sw { namespace ctrl {

	class VisualControl : ControlBase {
	private:
		graph::Bitmap* m_RenderBuffer;
	public:
		VisualControl();
		virtual ~VisualControl();

		virtual void drawOn(graph::Bitmap* target, util::Point offset);
		virtual void redraw();
	};

}}

