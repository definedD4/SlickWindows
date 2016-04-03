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
		
		Point m_Origin;

	public:
		Renderer(Window* target);
		~Renderer();

		void setOrigin(const Point& origin);

		Point originToWindow(const Point& point) const;
		Rect originToWindow(const Rect& rect) const;

		Vec2f transform(const Point& point) const;
		Rectf transform(const Rect& rect) const;

		void fillRect(const Rect& rect, Color color);
	};

}
