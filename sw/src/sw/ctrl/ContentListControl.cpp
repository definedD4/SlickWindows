#include "ContentListControl.h"

namespace sw {
	namespace ctrl {

		ContentListControl::ContentListControl() 
			: ContainerControl(), ControlBase() {
		}

		ContentListControl::~ContentListControl() {
			for (ControlBase* item : m_Children) {
				delete item;
			}
		}
	}
}