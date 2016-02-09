#pragma once

#include "VisualControl.h"
#include "LayoutControl.h"

namespace sw {
	namespace ctrl {

		class Test_Rect : public virtual VisualControl,
			public virtual LayoutControl {
		public:
			Test_Rect() : VisualControl(), LayoutControl() {

			}
			virtual ~Test_Rect() {

			}

			Property<util::Color> Fill;

			virtual void render() {
				getRenderBuffer()->clear(Fill());
				ControlBase::render();
			}

			virtual void redraw() {
				render();
			}
		};

	}
}