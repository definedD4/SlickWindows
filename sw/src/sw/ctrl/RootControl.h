#pragma once

#include "sw/Common.h"

#include "sw/ctrl/ControlParrent.h"

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

		virtual Size getContainerArea(ControlBase* control) const;
		virtual Point transformToWindowSpace(Point point, const ControlBase* const control) const;
		virtual Renderer* getRenderer() const;

		void setContent(ControlBase* content);

		void render();
		void resize();
	};

}

#include "sw/Window.h"
