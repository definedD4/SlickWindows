#pragma once

#include "sw/util/Point.h"
#include "sw/util/Size.h"
#include "sw/util/Thickness.h"
#include "sw/util/Dimension.h"

#include "sw/fmwk/Property.h"
#include "sw/fmwk/PropertyContainer.h"

#include "sw/ctrl/Misc.h"
#include "sw/ctrl/ControlParrent.h"

namespace sw { 
	
	class Renderer;
	
	class ControlParrent;

	class ControlBase : public virtual PropertyContainer {
	private:
		ControlParrent* m_Parrent;

		Point m_Position;
		Size m_Size;


	public:
		ControlBase();
		virtual ~ControlBase();

	private:
		void setParrent(ControlParrent* parrent);

	protected:
		ControlParrent* getParrent() const;

		void setPosition(Point position);

		void setSize(Size size);

		virtual Renderer getDrawRenderer();

	public:
		Size getSize() const;
		Point getPosition() const;

		//virtual Point transformToWindowSpace(Point point) const;
		//Point getOrigin() const;
		virtual Size getDesiredSize() const;

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
