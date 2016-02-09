#include "ContentListControl.h"

namespace sw {
	namespace ctrl {

		ContentListControl::ContentListControl() {}

		ContentListControl::~ContentListControl() {}

		void ContentListControl::redraw() {
			suspendRendering();
			for (ControlBase* item : *getItems()) {
				item->redraw();
			}
			resumeRendering();
			render();
		}
	}
}