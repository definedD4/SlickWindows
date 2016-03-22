#include "LayoutControl.h"

namespace sw {

	LayoutControl_::LayoutControl_() {}

	LayoutControl_::~LayoutControl_() {}

	void LayoutControl_::resize() {
		Size contArea = getParrent()->getContainerArea(this);
		Size newSize;
		Point newPosition;

		int w_full = contArea.w - Margin().l - Margin().r;
		if (Width().isAuto() || Width().getValue() >= w_full) {
			newSize.w = w_full;
			newPosition.x = Margin().l;
		} else {
			newSize.w = Width().getValue();
			if (this->HorizontalLayout() == HorizontalLayout::Left) {
				newPosition.x = Margin().l;
			} else if (this->HorizontalLayout() == HorizontalLayout::Right) {
				newPosition.x = contArea.w - Margin().r - newSize.w;
			} else if (this->HorizontalLayout() == HorizontalLayout::Center) {
				newPosition.x = (contArea.w - newSize.w) / 2;
			}
		}

		int h_full = contArea.h - Margin().t - Margin().b;
		if (Height().isAuto() || Height().getValue() >= h_full) {
			newSize.h = h_full;
			newPosition.y = Margin().t;
		} else {
			newSize.h = Height().getValue();
			if (this->VerticalLayout() == VerticalLayout::Up) {
				newPosition.y = Margin().t;
			} else if (this->VerticalLayout() == VerticalLayout::Down) {
				newPosition.y = contArea.h - Margin().b - newSize.h;
			} else if (this->VerticalLayout() == VerticalLayout::Center) {
				newPosition.y = (contArea.h - newSize.h) / 2;
			}
		}

		setSize(newSize);
		setPosition(newPosition);
	}
}

