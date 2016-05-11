#pragma once

#include "sw/graph/RenderTarget.h"
#include "sw/Window.h"

namespace sw {

	class WindowRenderTarget : public virtual RenderTarget
	{
	private:
		const Window* m_Window;

	public:
		WindowRenderTarget() = delete;
		WindowRenderTarget(const WindowRenderTarget& other) = delete;
		WindowRenderTarget(const Window* window);
		virtual ~WindowRenderTarget();


		virtual void beginRender() override;
		virtual void endRender() override;
		virtual Size getSize() const override;
	};	
	
}
