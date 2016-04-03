#pragma once

#include <ostream>

namespace sw { 

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

		void operator=(const Point& src) {
			x = src.x;
			y = src.y;
		}

		friend Point operator +(Point& left, Point& right);
		friend Point operator -(Point& left, Point& right);

	};

	inline Point operator +(const Point& left, const Point& right) {
		return Point(left.x + right.x, left.y + right.y);
	}

	inline Point operator -(const Point& left, const Point& right) {
		return Point(left.x - right.x, left.y - right.y);
	}

	inline std::ostream& operator << (std::ostream& stream, const Point& point) {
		stream << "pt{" << point.x << "," << point.y << "}";
		return stream;
	}

}

