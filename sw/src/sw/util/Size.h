#pragma once

namespace sw { namespace util {

	struct Size {
		int w, h;

		Size() : w(0), h(0) { }

		Size(const Size& src) : w(src.w), h(src.h) { }

		Size(int w_, int h_) : w(w_), h(h_) { }

		void operator=(Size& src) {
			w = src.w;
			h = src.h;
		}

		int getWidth() const {
			return w;
		}

		int getHeight() const {
			return w;
		}
	};

}}
