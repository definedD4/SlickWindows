#pragma once

#include "Point.h"
#include "Size.h"

namespace sw { namespace util {

	struct Rect {
		Point p1, p2;

		Rect() { }

		Rect(const Rect& src) : p1(src.p1), p2(src.p2) { }

		Rect(const Point& p1_, const Point& p2_) : p1(p1_), p2(p2_) { }

		Rect(int x, int y, int w, int h) : p1(x, y), p2(x + w, y + h) { }

		Rect(const Point& p, const Size& sz) : p1(p), p2(p.x + sz.w, p.y + sz.h) { }

		void operator=(const Rect& src) {
			p1 = src.p1;
			p2 = src.p2;
		}

		int getX1() const {
			return p1.x;
		}

		int getY1() const {
			return p1.y;
		}

		int getX2() const {
			return p2.x;
		}

		int getY2() const {
			return p2.y;
		}
	};

}}

