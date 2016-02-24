#pragma once

#include "sw/Common.h"

namespace sw { 

	struct Color {
		byte r, g, b, a;

		Color() : r(0), g(0), b(0), a(0) { }
		Color(byte r_, byte g_, byte b_, byte a_) : r(r_), g(g_), b(b_), a(a_) { }

		Color(const Color& src) : r(src.r), g(src.g), b(src.b), a(src.a) { }

		void operator=(Color& src) {
			r = src.r;
			g = src.g;
			b = src.g;
			a = src.a;
		}
	};

	namespace Colors {
		const Color red   = Color(255, 0  , 0  , 255);
		const Color green = Color(0  , 255, 0  , 255);
		const Color blue  = Color(0  , 0  , 255, 255);
		const Color white = Color(255, 255, 255, 255);
		const Color black = Color(0  , 0  , 0  , 255);
	}

}

