#pragma once

#include "../common.h"

namespace sw { namespace util {

	struct Color {
		byte r, g, b, a;

		Color(byte r_, byte g_, byte b_, byte a_) : r(r_), g(g_), b(b_), a(a_) { }

		Color(const Color& src) : r(src.r), g(src.g), b(src.b), a(src.a) { }

		void operator=(Color& src) {
			r = src.r;
			g = src.g;
			b = src.g;
			a = src.a;
		}
	};

}}

