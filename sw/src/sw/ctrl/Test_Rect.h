#pragma once

#include "LayoutControl.h"

namespace sw {
	namespace ctrl {

		class Test_Rect : public virtual LayoutControl {
		public:
			Test_Rect() : LayoutControl() {

			}
			virtual ~Test_Rect() {

			}

			Property<util::Color> Fill;

			virtual void render() {
				getRenderer()->fillRect(util::Rect(transformToWindowSpace(util::Point()),
					transformToWindowSpace(util::Point(getSize().w, getSize().h))),
					Fill());
			}

		};

	}
}