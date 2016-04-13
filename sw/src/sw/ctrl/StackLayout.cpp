#include "StackLayout.h"

namespace sw {

	StackLayout::StackLayout() : LayoutControl()
	{
	}


	StackLayout::~StackLayout()
	{
	}

	void* StackLayout::onChildAdded(ControlBase* child) {
		child_info* data = new child_info();
		data->offset = m_InsertOffset;
		return data;
	}

	Size StackLayout::getContainerArea(ControlBase* control) const {
		return ((child_info*)std::find_if(getChildren().begin(), getChildren().end(),
			[control](const child_data& entry) { return entry.childPtr == control;  })->customData)->container;
	}

	Point StackLayout::transformToWindowSpace(Point point, const ControlBase* const control) const {
		return point + getPosition() + Point(0, ((child_info*)std::find_if(getChildren().begin(), getChildren().end(),
			[control](const child_data& entry) { return entry.childPtr == control;  })->customData)->offset);
	}

	void StackLayout::resize() {
		ControlBase::resize();

		Size containerSize = getParrent()->getContainerArea(this);

		m_InsertOffset = 0;

		for(auto item : getChildren()) {
			Size desiredSize = item.childPtr->getDesiredSize();

			setIfMax(m_MaxElemWidth, desiredSize.w);

			child_info* custom = (child_info*)item.customData;

			custom->offset = m_InsertOffset;
			custom->container = Size(min(desiredSize.w, containerSize.w), desiredSize.h);

			m_InsertOffset += desiredSize.h;

			item.childPtr->resize();
		}
	}

	void StackLayout::render() {
		for(auto item : getChildren()) {
			item.childPtr->render();
		}
	}
}
