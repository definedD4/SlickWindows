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
		return ((child_info*)getChildren().at(control))->container;
	}

	//Point StackLayout::transformToWindowSpace(Point point, const ControlBase* const control) const {
	//	return point + getPosition() + Point(0, ((child_info*)std::find_if(getChildren().begin(), getChildren().end(),
	//		[control](const child_data& entry) { return entry.childPtr == control;  })->customData)->offset);
	//}


	Renderer StackLayout::getRenderer(ControlBase* control) {
		return getParrent()->getRenderer(static_cast<ControlBase*>(this))
			.createWithOffset(Point(0, ((child_info*)getChildren().at(control))->offset));
	}

	void StackLayout::resize() {
		ControlBase::resize();

		Size containerSize = getParrent()->getContainerArea(this);

		m_InsertOffset = 0;

		for(auto item : getChildren()) {
			Size desiredSize = item.first->getDesiredSize();

			setIfMax(m_MaxElemWidth, desiredSize.w);

			child_info* custom = (child_info*)item.second;

			custom->offset = m_InsertOffset;
			custom->container = Size(min(desiredSize.w, containerSize.w), desiredSize.h);

			m_InsertOffset += desiredSize.h;

			item.first->resize();
		}
	}

	void StackLayout::render() {
		for(auto item : getChildren()) {
			item.first->render();
		}
	}
}
