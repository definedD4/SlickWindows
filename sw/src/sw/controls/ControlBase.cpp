#include "ControlBase.h"

using namespace sw::util;
using namespace sw::graph;

namespace sw { namespace controls {


	ControlBase::ControlBase(ControlBase* parrent, util::Point position, util::Size size)
		: m_Parrent(parrent), m_Position(position), m_Size(size) {
		m_RenderBuffer = new Bitmap(m_Size);
	}

	ControlBase::~ControlBase() {
		delete m_RenderBuffer;
	}

	void ControlBase::drawOn(graph::Bitmap* dest) const {
		dest->drawImage(m_Position, m_RenderBuffer);
	}
}}

