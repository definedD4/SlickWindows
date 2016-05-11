#pragma once

#include "sw/Common.h"

#include "sw/ctrl/ControlParrent.h"
#include "sw/Window.h"

namespace sw {

	class Window;
	class Renderer;
	class ControlBase;

	class RootControl : public virtual ControlParrent {
	private:
		Window* m_Owner;
		ControlBase* m_Content;

	public:
		RootControl(Window* owner);
		RootControl(const RootControl& other) = delete;
		virtual ~RootControl();

		virtual Size getContainerArea(ControlBase* control) const override;
		//virtual Point transformToWindowSpace(Point point, const ControlBase* const control) const override;
		virtual Renderer getRenderer(ControlBase* control) const override;

		void setContent(ControlBase* content);

		void render();
		void resize();
	};

}

