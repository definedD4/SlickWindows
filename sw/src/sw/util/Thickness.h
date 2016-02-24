#pragma once

namespace sw { 
	
	struct Thickness {
		int t, r, b, l;

		Thickness() : t(0), r(0), b(0), l(0) { }
		Thickness(int t_, int r_, int b_, int l_)
			: t(t_), r(r_), b(b_), l(l_) { }
	};

}

