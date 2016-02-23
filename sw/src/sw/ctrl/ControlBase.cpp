#include "ControlBase.h"

namespace sw { namespace ctrl {

	ControlBase::ControlBase() : 
		PropertyContainer() {}

	ControlBase::~ControlBase() {}

	ContainerControl* ControlBase::getParrent() const {
		return m_Parrent;
	}

	Renderer* ControlBase::getRenderer() const {
		return m_Parrent->getRenderer();
	}

	util::Point ControlBase::transformToWindowSpace(util::Point point) const {
		return m_Parrent->transformToWindowSpace(point + m_Position);
	}

} }