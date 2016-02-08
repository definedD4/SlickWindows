#pragma once

#include "../util/Point.h"
#include "../util/Size.h"
#include "../graph/Bitmap.h"

namespace sw { namespace ctrl {
	
	class ContainerControl;

	class ControlBase {
	private:
		ContainerControl* m_Parrent;

		util::Point m_Position;
		util::Size m_Size;

		bool m_RenderRequested = false;
		bool m_RedrawRequested = false;

	protected:
		bool isRenderRequested() const {
			return m_RenderRequested;
		}
		bool isRedrawRequested() const {
			return m_RedrawRequested;
		}

		util::Point getPosition() const {
			return m_Position;
		}

	public:
		ControlBase();
		virtual ~ControlBase();

		virtual void render();
		virtual void redraw();
		void requestRender() {
			m_RenderRequested = true;
		}
		void requestRedraw() {
			m_RedrawRequested = true;
		}
		virtual void drawOn(graph::Bitmap* target, util::Point offset) = 0;

		virtual void resize() = 0;
	};

} }

#include "ContainerControl.h"