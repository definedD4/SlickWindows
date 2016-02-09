#pragma once

#include "../Common.h"
#include "../Window.h"
#include "ContainerControl.h"

namespace sw {
	namespace ctrl {

		class RootControl : public virtual ContainerControl {
		private:
			Window* m_Owner;
			ControlBase* m_Content;

		public:
			RootControl(Window* owner);
			RootControl(const RootControl& other) = delete;
			virtual ~RootControl();

			virtual util::Size getContainerArea(ControlBase* control);
			void setContent(ControlBase* content);

			virtual void render();
			virtual void redraw();

			virtual void drawOn(graph::Bitmap* target, util::Point offset) { }
			virtual void resize() {
				setSize(m_Owner->getSize());
			}
		};

	}
}