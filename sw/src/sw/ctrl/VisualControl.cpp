#include "VisualControl.h"

namespace sw { namespace ctrl {


	VisualControl::VisualControl() : ControlBase() {}

	VisualControl::~VisualControl() {
		delete m_RenderBuffer;
	}

	void VisualControl::drawOn(graph::Bitmap* target, util::Point offset) {
		WARN(!m_RenderBuffer, "Trying to render control without render buffer.")
		if(m_RenderBuffer)
			target->drawImage(getPosition() + offset, m_RenderBuffer);
	}

	void VisualControl::redraw() {
		render();
	}
} }