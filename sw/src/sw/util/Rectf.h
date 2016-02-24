#pragma once

#include "sw/util/Vec2f.h"

namespace sw {
	
	struct Rectf {
		Vec2f v1, v2;

		Rectf(Vec2f v1_, Vec2f v2_) : v1(v1_), v2(v2_) { }
		Rectf(const Rectf& src) : v1(src.v1), v2(src.v2) { }
	};

}

