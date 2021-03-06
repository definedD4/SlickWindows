#pragma once

#include <ostream>

#include "sw/util/Thickness.h"

namespace sw {

	struct Size {
		int w, h;

		Size() : w(0), h(0) { }

		Size(const Size& src) : w(src.w), h(src.h) { }

		Size(int w_, int h_) : w(w_), h(h_) { }

		void operator=(const Size& src) {
			w = src.w;
			h = src.h;
		}

		int getWidth() const {
			return w;
		}

		int getHeight() const {
			return h;
		}
	};

	inline std::ostream& operator << (std::ostream& stream, Size& size) {
		stream << "sz{" << size.w << "," << size.h << "}";
		return stream;
	}

	inline Size operator +(const Size& size, const Thickness& thickness) {
		return Size(size.w + thickness.l + thickness.r, size.h + thickness.t + thickness.b);
	}

}

