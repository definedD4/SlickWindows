#pragma once

namespace sw { namespace util {

	struct Point {
		int x, y;

		Point() : x(0), y(0) { }

		Point(const Point& src) : x(src.x), y(src.y) { }

		Point(int x_, int y_) : x(x_), y(y_) { }

		int getX() const {
			return x;
		}

		int getY() const {
			return y;
		}

		void operator=(Point& src) {
			x = src.x;
			y = src.y;
		}

		friend Point operator +(Point& left, Point& right);
		friend Point operator -(Point& left, Point& right);

	};

	inline Point operator +(Point& left, Point& right) {
		return Point(left.x + right.x, left.y + right.y);
	}

	inline Point operator -(Point& left, Point& right) {
		return Point(left.x - right.x, left.y - right.y);
	}

}}

