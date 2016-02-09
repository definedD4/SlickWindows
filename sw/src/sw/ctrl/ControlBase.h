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

		bool m_RenderingSuspended = false;

		void setParrent(ContainerControl* parrent) { m_Parrent = parrent; }

	protected:
		ContainerControl* getParrent() const { return m_Parrent; }

		util::Point getPosition() const {
			return m_Position;
		}
		void setPosition(util::Point position) {
			m_Position = position;
		}
		void setSize(util::Size size) {
			m_Size = size;
		}

		bool isRenderingSuspended() const { return m_RenderingSuspended; }
		void suspendRendering() { m_RenderingSuspended = true; }
		void resumeRendering() { m_RenderingSuspended = false; }

	public:
		ControlBase();
		virtual ~ControlBase();

		virtual void render();
		virtual void redraw() = 0;
		virtual void drawOn(graph::Bitmap* target, util::Point offset) = 0;
		virtual void resize() = 0;

		friend class RootControl;
	};

} }

#include "ContainerControl.h"