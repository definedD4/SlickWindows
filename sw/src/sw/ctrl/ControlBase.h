#pragma once

#include "sw/util/Point.h"
#include "sw/util/Size.h"

#include "sw/Property.h"
#include "sw/util/Thickness.h"
#include "sw/util/Dimension.h"

#include "Misc.h"
#include "sw/PropertyContainer.h"

namespace sw { 
	
	class Renderer;
	
	class ControlParrent;

	class ControlBase : public virtual PropertyContainer {
	private:
		ControlParrent* m_Parrent;

		Point m_Position;
		Size m_Size;

		void setParrent(ControlParrent* parrent) { m_Parrent = parrent; }

	protected:
		ControlParrent* getParrent() const;

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
		virtual void resize();

		Property<Dimension> Width;
		Property<Dimension> Height;
		Property<Thickness> Margin;
		Property<HorizontalLayout> HorizontalLayout;
		Property<VerticalLayout> VerticalLayout;

		friend class RootControl;
		friend class LayoutControl;
	};

}

#include "sw/ctrl/ContainerControl.h"

#include "sw/Renderer.h"
