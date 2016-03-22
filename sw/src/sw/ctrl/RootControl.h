#pragma once

#include "sw/Common.h"

#include "sw/ctrl/ControlBase.h"

namespace sw {

	class Window;
	class Renderer;

	class RootControl : public virtual ControlParrent {
	private:
		Window* m_Owner;
		ControlBase* m_Content;

	protected:
		virtual Renderer* getRenderer() const;

	public:
		RootControl(Window* owner);
		RootControl(const RootControl& other) = delete;
		virtual ~RootControl();

		virtual Size getContainerArea(ControlBase* control);
		void setContent(ControlBase* content);

		virtual Point transformToWindowSpace(Point point) const {
			return point;
		}

		virtual void render();
		virtual void resize();
	};

}

#include "sw/Window.h"
