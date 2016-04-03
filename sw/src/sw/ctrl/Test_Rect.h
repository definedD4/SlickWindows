#pragma once

#include "LayoutControl.h"

namespace sw {
	

		class Test_Rect : public virtual ControlBase {
		public:
			Test_Rect() : ControlBase() {

			}
			virtual ~Test_Rect() {

			}

			Property<Color> Fill;

			virtual void render() {
				getRenderer()->setOrigin(getOrigin());

				Rect fillRect(Point(), Point(getSize().w, getSize().h));

				getRenderer()->fillRect(fillRect, Fill());
			}

		};

	}