#include "ContentListControl.h"

namespace sw {

		ContentListControl::ContentListControl() 
			: ContainerControl(), ControlBase() {
		}

		ContentListControl::~ContentListControl() {
			for (ControlBase* item : m_Children) {
				delete item;
			}
		}
}