#pragma once

namespace sw { namespace util {

	inline int max(int a, int b) {
		return a > b ? a : b;
	}

	inline int min(int a, int b) {
		return a < b ? a : b;
	}

	inline int clamp(int val, int min_val, int max_val) {
		return min(max(val, min_val), max_val);
	}

}}

