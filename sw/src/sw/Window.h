#pragma once

#include <iostream>
#include <string>

#include "Common.h"

#include "util/Size.h"

#include "sw/graph/RenderTarget.h"

#include "sw/GLFWWindowHost.h"

#include "ctrl/RootControl.h"

namespace sw {


	class ControlBase;
	class RootControl;
	class Renderer;

	class Window : public virtual GLFWWindowHost {
	private:
		RootControl* m_Root;

	public:
		Window(const Size& size, const std::string& title);
		virtual ~Window();

		RenderTarget* getRenderTarget() const;

		void setContent(ControlBase* content);

		virtual void onRender() override;
		virtual void onSizeChanged() override;
	};

}

#include "ctrl/RootControl.h"

