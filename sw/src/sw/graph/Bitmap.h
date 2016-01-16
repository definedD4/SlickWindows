#pragma once

#include "../Common.h"
#include "../util/Size.h"
#include "../util/Rect.h"
#include "../util/Color.h"
#include "../util/Math.h"

#define BITMAP_BYTES_PER_PIXEL 4;

using namespace sw;
using namespace util;

namespace sw {
	namespace graph {

		class Bitmap {
		private:
			Size m_Size;
			int m_BytesPerPixel, m_Stride, m_Length;

			byte* m_Pixels;

		public:
			Bitmap(Size& size);
			~Bitmap();

			Size getSize() const { return m_Size; }
			int getStride() const { return m_Stride; }
			int getLength() const { return m_Length; }
			byte* getPixels() { return m_Pixels; }

			void fillRect(Rect r, Color c);
			void drawRect(Rect r, Color c, int thickness);
			void fillDrawRect(Rect r, Color backgroung, Color border, int thickness);
		};

	}
}