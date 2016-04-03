#pragma once

#include "sw/Common.h"
#include "sw/Application.h"

namespace sw { 
	
	class Dimension {
	private:
		bool m_Auto = false;
		int m_Value;

		Dimension(bool Auto, int value) : m_Auto(Auto), m_Value(value) {}
	public:
		Dimension() : m_Auto(true), m_Value(0) { }
		~Dimension() {}

		Dimension(const Dimension& other) : m_Auto(other.m_Auto), m_Value(other.m_Value) {}

		static Dimension Auto() { return Dimension(true, 0); }
		static Dimension fromInt(int val) { return Dimension(false, val); }

		bool isAuto() const { return m_Auto; }
		int getValue() const {
			ASSERT(!m_Auto)
			return m_Value;
		}

		int valueOr(int def) {
			if (!isAuto()) {
				return m_Value;
			}
			else {
				return def;
			}
		}
	};

} 