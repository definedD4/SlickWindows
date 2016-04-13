#pragma once

namespace sw { 

	inline int max(int a, int b) {
		return a > b ? a : b;
	}

	inline int min(int a, int b) {
		return a < b ? a : b;
	}

	inline int clamp(int val, int min_val, int max_val) {
		return min(max(val, min_val), max_val);
	}

	inline int setIfMax(int& var, int val) {
		if(var < val) {
			var = val;
		}
		return var;
	}
	inline int setIfMin(int& var, int val) {
		if (var > val) {
			var = val;
		}
		return var;
	}
}

