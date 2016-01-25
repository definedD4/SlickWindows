#pragma once

namespace sw { namespace util {
	
	struct Thikness {
		int t, r, b, l;

		Thikness() : t(0), r(0), b(0), l(0) { }
		Thikness(int t_, int r_, int b_, int l_)
			: t(t_), r(r_), b(b_), l(l_) { }
	};

}}

