#pragma once

#include "sw/util/Point.h"
#include "sw/util/Size.h"
#include "sw/PropertyContainer.h"

namespace sw { 
	
	class Renderer;
	
	class ContainerControl;

	class ControlBase : public virtual PropertyContainer {
	private:
		ContainerControl* m_Parrent;

		Point m_Position;
		Size m_Size;

		void setParrent(ContainerControl* parrent) { m_Parrent = parrent; }

	protected:
		ContainerControl* getParrent() const;

		void setPosition(Point position) {
			m_Position = position;
		}

		void setSize(Size size) {
			m_Size = size;
		}

		virtual Renderer* getRenderer() const;

	public:
		ControlBase();
		virtual ~ControlBase();

		Size getSize() const { return m_Size; }
		Point getPosition() const { return m_Position; }

		virtual Point transformToWindowSpace(Point point) const;

		virtual void render() = 0;
		virtual void resize() = 0;


		friend class RootControl;
		friend class ContentListControl;
	};

}

#include "sw/ctrl/ContainerControl.h"

#include "sw/Renderer.h"
