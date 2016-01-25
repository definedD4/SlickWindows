#pragma once

#include "ContainerControl.h"
#include "../graph/Bitmap.h"

namespace sw { namespace controls {

	class ContainerControl;

	class ControlBase {
	private:
		ContainerControl* m_Parrent;

		util::Point m_Position;
		util::Size m_Size;

		graph::Bitmap* m_RenderBuffer;

		void setParrent(ContainerControl* parrent) { m_Parrent = parrent; }

	protected:
		void setPosition(util::Point position) { m_Position = position; }
		void setSize(util::Size size) { m_Size = size; }

		ContainerControl* getParrent() const { return m_Parrent; }
		graph::Bitmap* getRenderBuffer() const { return m_RenderBuffer; }

	public:
		ControlBase(ContainerControl* parrent, util::Point position, util::Size size);
		virtual ~ControlBase();

		util::Point getPosition() const { return m_Position; }
		const util::Size& getSize() const { return m_Size; }

		void drawOn(graph::Bitmap* dest) const;

		virtual void render() = 0;
		virtual void resize() = 0;
		virtual void redraw() = 0;

		friend class RootControl;
	};

}}

