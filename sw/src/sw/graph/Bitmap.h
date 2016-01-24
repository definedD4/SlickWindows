#pragma once

#include "../Common.h"
#include "../util/Size.h"
#include "../util/Rect.h"
#include "../util/Color.h"
#include "../util/Math.h"

#define BITMAP_BYTES_PER_PIXEL 4;

namespace sw {
	namespace graph {

		class Bitmap {
		private:
			util::Size m_Size;
			int m_BytesPerPixel, m_Stride, m_Length;

			byte* m_Pixels;

		public:
			Bitmap(util::Size size);
			~Bitmap();

			util::Size getSize() const { return m_Size; }
			int getStride() const { return m_Stride; }
			int getLength() const { return m_Length; }
			byte* getPixels() { return m_Pixels; }

			void drawImage(util::Point p, Bitmap* src);
			void clear(util::Color c);

			void fillRect(const util::Rect& r, util::Color c);
			void drawRect(util::Rect r, util::Color c, int thickness);
			void fillDrawRect(util::Rect r, util::Color backgroung, util::Color border, int thickness);
		};

	}
}