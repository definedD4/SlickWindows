#pragma once

#include "../Common.h"
#include "../Application.h"

namespace sw { namespace util {
	
	class Dimension {
	private:
		bool m_Auto = false;
		int m_Value;

		Dimension(bool Auto, int value) : m_Auto(Auto), m_Value(value) {}
	public:
		Dimension() {
			m_Auto = true;
		}
		~Dimension() {}

		Dimension(const Dimension& other) : m_Auto(other.isAuto()), m_Value(other.getValue()) {}

		static Dimension Auto() { return Dimension(true, 0); }
		static Dimension fromInt(int val) { return Dimension(false, val); }

		bool isAuto() const { return m_Auto; }
		int getValue() const {
			ASSERT(!m_Auto)
			return m_Value;
		}
	};

} }