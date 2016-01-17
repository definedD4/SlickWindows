#include "VisualControl.h"

using namespace sw::util;
using namespace sw::graph;

namespace sw { namespace controls {

	VisualControl::VisualControl() {
		m_RenderBuffer = new Bitmap(getSize());
	}

	VisualControl::VisualControl(util::Size size, util::Point position, Color fill)
		: LayoutControl(size, position), m_Fill(fill) {
		m_RenderBuffer = new Bitmap(getSize());	
	}

	VisualControl::~VisualControl() { 
		delete m_RenderBuffer;
	}

	void VisualControl::drawOn(Bitmap* dest) {
		dest->drawImage(getPosition(), m_RenderBuffer);
	}

	void VisualControl::onRender() {
		m_RenderBuffer->fillRect(Rect(Point(), getSize()), m_Fill);
	}

	void VisualControl::onResize() {
		
	}


}}

