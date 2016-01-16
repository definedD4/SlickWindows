#include "Bitmap.h"

#include "../util/rect.h"
#include "../util/color.h"
#include "../util/math.h"

namespace sw {
	namespace graph {

		Bitmap::Bitmap(Size& size) {
			m_Size = size;
			m_BytesPerPixel = BITMAP_BYTES_PER_PIXEL;
			m_Stride = m_Size.w * m_BytesPerPixel;
			m_Length = m_Stride * m_Size.h;

			m_Pixels = new byte[m_Length];
			for (int i = 0; i < m_Length; i++) {
				m_Pixels[i] = 255;
			}
		}

		Bitmap::~Bitmap() {
			delete[] m_Pixels;
		}

		void Bitmap::fillRect(Rect r, Color c) {
			int y1 = max(r.getY1(), 0);
			if (y1 > m_Size.h) return;

			int y2 = min(r.getY2(), m_Size.h);

			int x1 = max(r.getX1(), 0);
			if (x1 > m_Size.w) return;

			int x2 = min(r.getX2(), m_Size.w);

			for (int y = y1; y <= y2; y++) {
				int ind = y * m_Stride + x1 * m_BytesPerPixel;
				int ind_e = y * m_Stride + x2 * m_BytesPerPixel;
				while (ind < ind_e) {
					m_Pixels[ind++] = c.r;
					m_Pixels[ind++] = c.g;
					m_Pixels[ind++] = c.b;
					m_Pixels[ind++] = c.a;
				}
			}
		}

		void Bitmap::drawRect(Rect r, Color c, int thickness) {

		}

		void Bitmap::fillDrawRect(Rect r, Color backgroung, Color border, int thickness) {

		}
	}
}
