#pragma once

namespace sw {
	struct Vec2f {
		float x, y;

		Vec2f() : x(0), y(0) { }
		Vec2f(float x_, float y_) : x(x_), y(y_) { }
		Vec2f(const Vec2f& src) : x(src.x), y(src.y) { }

	};

}