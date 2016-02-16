#include "VisualControl.h"

namespace sw { namespace ctrl {

	VisualControl::VisualControl() : ControlBase() {
		m_RenderBuffer = new graph::Bitmap(getSize());
		ResizeEvent.addHandler([&](ControlBase::ResizeEventArgs args) {
			m_RenderBuffer = new graph::Bitmap(getSize());
		});
	}

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