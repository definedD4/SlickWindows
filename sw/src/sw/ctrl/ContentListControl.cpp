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

		void ContentListControl::redraw() {
			suspendRendering();
			for (ControlBase* item : m_Children) {
				item->redraw();
			}
			resumeRendering();
			render();
		}
	}
}