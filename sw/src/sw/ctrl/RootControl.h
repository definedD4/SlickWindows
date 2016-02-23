#pragma once

#include "../Common.h"
#include "ContainerControl.h"
#include "../Window.h"

namespace sw {

	class Window;
	class Renderer;

	namespace ctrl {

		class ContainerControl;
		class ControlBase;

		class RootControl : public virtual ContainerControl {
		private:
			Window* m_Owner;
			ControlBase* m_Content;

		protected:
			virtual Renderer* getRenderer() const;

		public:
			RootControl(Window* owner);
			RootControl(const RootControl& other) = delete;
			virtual ~RootControl();

			virtual util::Size getContainerArea(ControlBase* control);
			void setContent(ControlBase* content);

			virtual util::Point transformToWindowSpace(util::Point point) const {
				return point;
			}

			virtual void render();
			virtual void resize();
		};

	}
}
