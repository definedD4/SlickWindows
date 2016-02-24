#include "Renderer.h"

namespace sw {

	Renderer::Renderer(Window* target) : m_Target(target) {

	}

	Renderer::~Renderer() {

	}

	Vec2f Renderer::transform(Point point) {
		Size targetSize = m_Target->getSize();
		float x = (float)point.x / targetSize.w * 2.0f - 1.0f;
		float y = (float)point.y / targetSize.h * 2.0f - 1.0f;
		return Vec2f(x, y);
	}

	Rectf Renderer::transform(Rect rect) {
		Vec2f v1 = transform(rect.p1);
		Vec2f v2 = transform(rect.p2);
		return Rectf(v1, v2);
	}

	void Renderer::fillRect(const Rect& rect, Color color) {
		Rectf rect_t = transform(rect);

		m_Target->makeContextCurrent();

		/*
		0 v1               1 3 
		 x------------------x
		 |            ======|
		 |      ======      |
		 |======            |
		 x------------------x
		2 4                5 v2
		*/

		glBegin(GL_TRIANGLES);
		glColor3f(color.r, color.g, color.b);
		glVertex2f(rect_t.v1.x, rect_t.v1.y);
		glVertex2f(rect_t.v2.x, rect_t.v1.y);
		glVertex2f(rect_t.v1.x, rect_t.v2.y);
		glVertex2f(rect_t.v2.x, rect_t.v1.y);
		glVertex2f(rect_t.v1.x, rect_t.v2.y);
		glVertex2f(rect_t.v2.x, rect_t.v2.y);
		glEnd();
	}

}