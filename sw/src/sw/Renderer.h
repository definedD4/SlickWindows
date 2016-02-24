#pragma once

#include "sw/util/Point.h"
#include "sw/util/Rect.h"
#include "sw/util/Vec2f.h"
#include "sw/util/Rectf.h"
#include "sw/util/Color.h"
#include "sw/Window.h"

namespace sw {

	class Window;

	class Renderer
	{
	private:
		Window* m_Target;

	public:
		Renderer(Window* target);
		~Renderer();

		Vec2f transform(Point point);
		Rectf transform(Rect rect);

		void fillRect(const Rect& rect, Color color);
	};

}
