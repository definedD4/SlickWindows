#include "ControlBase.h"

namespace sw { 

	ControlBase::ControlBase() : 
		PropertyContainer() {}

	ControlBase::~ControlBase() {}

	ContainerControl* ControlBase::getParrent() const {
		return m_Parrent;
	}

	Renderer* ControlBase::getRenderer() const {
		return m_Parrent->getRenderer();
	}

	Point ControlBase::transformToWindowSpace(Point point) const {
		return m_Parrent->transformToWindowSpace(point + m_Position);
	}

}