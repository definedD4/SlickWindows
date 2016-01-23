#pragma once

#include "../Common.h"
#include "../graph/Bitmap.h"

namespace sw { namespace controls {

	class ControlBase {
	private:
		ControlBase* m_Parrent;

		util::Point m_Position;
		util::Size m_Size;

		graph::Bitmap* m_RenderBuffer;

	protected:
		void setPosition(util::Point position) { m_Position = position; }
		void setSize(util::Size size) { m_Size = size; }

		graph::Bitmap* getRenderBuffer() const { return m_RenderBuffer; }

	public:
		ControlBase(ControlBase* parrent, util::Point position, util::Size size);
		virtual ~ControlBase();

		util::Point getPosition() const { return m_Position; }
		util::Size getSize() const { return m_Size; }

		void drawOn(graph::Bitmap* dest) const;

		virtual void render() = 0;
		virtual void resize() = 0;
	};

}}

