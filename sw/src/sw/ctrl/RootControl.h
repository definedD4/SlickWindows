#pragma once

#include "../Common.h"
#include "ContainerControl.h"
#include "../Window.h"

namespace sw {

	class Window;

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
			virtual void resize();
		};

	}
}
