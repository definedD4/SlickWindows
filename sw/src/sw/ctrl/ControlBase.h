#pragma once

#include "sw/util/Point.h"
#include "../util/Size.h"
#include "../Event.h"
#include "../PropertyContainer.h"
#include "sw/Renderer.h"

namespace sw { 
	
	class Renderer;

	namespace ctrl {
	
	class ContainerControl;

	class ControlBase : public virtual PropertyContainer {
	private:
		ContainerControl* m_Parrent;

		util::Point m_Position;
		util::Size m_Size;

		void setParrent(ContainerControl* parrent) { m_Parrent = parrent; }

	protected:
		ContainerControl* getParrent() const;

		void setPosition(util::Point position) {
			m_Position = position;
		}

		void setSize(util::Size size) {
			m_Size = size;
			//ResizeEvent.raiseEvent({ m_Size });
		}

		virtual Renderer* getRenderer() const;

	public:
		ControlBase();
		virtual ~ControlBase();

		util::Size getSize() const { return m_Size; }
		util::Point getPosition() const { return m_Position; }

		virtual util::Point transformToWindowSpace(util::Point point) const;

		virtual void render() = 0;
		virtual void resize() = 0;

		//EVENT(ResizeEvent, { util::Size newSize; })

		friend class RootControl;
		friend class ContentListControl;
	};

} }

#include "ContainerControl.h"
