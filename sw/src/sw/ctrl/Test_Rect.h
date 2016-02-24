#pragma once

#include "LayoutControl.h"

namespace sw {
	

		class Test_Rect : public virtual LayoutControl {
		public:
			Test_Rect() : LayoutControl() {

			}
			virtual ~Test_Rect() {

			}

			Property<Color> Fill;

			virtual void render() {
				getRenderer()->fillRect(Rect(transformToWindowSpace(Point()),
					transformToWindowSpace(Point(getSize().w, getSize().h))),
					Fill());
			}

		};

	}