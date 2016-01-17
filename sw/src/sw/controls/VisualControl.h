#pragma once

#include "../Common.h"
#include "../graph/Bitmap.h"
#include "LayoutControl.h"

namespace sw { namespace controls {

	class VisualControl : virtual LayoutControl{
	private:
		graph::Bitmap* m_RenderBuffer;

		util::Color m_Fill; //TODO: temporary

	public:
		VisualControl();
		VisualControl(util::Size size, util::Point position, util::Color fill); //TODO: temporary
		virtual ~VisualControl();

		void drawOn(graph::Bitmap* dest) override;

		void onRender() override;
		void onResize() override;
	};

}}

