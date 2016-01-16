#pragma once

#include "Point.h"
#include "Size.h"

namespace sw { namespace util {

	struct Rect {
		int x, y, w, h;

		Rect() : x(0), y(0), w(0), h(0) { }

		Rect(const Rect& src) : x(src.x), y(src.y), w(src.w), h(src.h) { }

		Rect(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) { }

		Rect(const Point& p, const Size& sz) : x(p.x), y(p.y), w(sz.w), h(sz.h) { }

		static Rect fromCoords(const Point& p1, const Point& p2) {
			return Rect(p1.x, p1.y, p2.x - p1.x, p2.y - p1.y);
		}

		static Rect fromCoords(int x1, int y1, int x2, int y2) {
			return Rect(x1, y1, x2 - x1, y2 - y1);
		}

		void operator=(Rect& src) {
			x = src.x;
			y = src.y;
			w = src.w;
			h = src.h;
		}

		int getX1() const {
			return x;
		}

		int getY1() const {
			return y;
		}

		int getX2() const {
			return x + w;
		}

		int getY2() const {
			return y + h;
		}
	};

}}

