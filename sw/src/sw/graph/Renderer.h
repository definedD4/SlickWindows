#pragma once

#include <GL/glew.h>

#include "sw/util/Point.h"
#include "sw/util/Rect.h"
#include "sw/util/Vec2f.h"
#include "sw/util/Rectf.h"
#include "sw/util/Color.h"

#include "sw/graph/RenderTarget.h"

namespace sw {

	class Renderer
	{
	private:
		RenderTarget* m_Target;
		
		Point m_Origin;

	public:
		Renderer(RenderTarget* target);
		Renderer(RenderTarget* target, const Point& origin);
		~Renderer();

		Renderer createWithOffset(const Point& offset) const;

		Point originToWindow(const Point& point) const;
		Rect originToWindow(const Rect& rect) const;

		Vec2f transform(const Point& point) const;
		Rectf transform(const Rect& rect) const;

		void fillRect(const Rect& rect, Color color);
	};

}
