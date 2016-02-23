#pragma once

#include "sw/Window.h"

#include "sw/util/Point.h"
#include "sw/util/Rect.h"
#include "sw/util/Vec2f.h"
#include "sw/util/Rectf.h"
#include "sw/util/Color.h"

namespace sw {

	class Window;

	class Renderer
	{
	private:
		Window* m_Target;

	public:
		Renderer(Window* target);
		~Renderer();

		util::Vec2f transform(util::Point point);
		util::Rectf transform(util::Rect rect);

		void fillRect(util::Rect rect, util::Color color);
	};

}