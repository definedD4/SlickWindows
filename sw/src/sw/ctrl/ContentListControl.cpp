#include "ContentListControl.h"

namespace sw {

		LayoutControl::LayoutControl() 
			: ControlParrent(), ControlBase() {
		}

		LayoutControl::~LayoutControl() {
			for (ControlBase* item : m_Children) {
				delete item;
			}
		}
}