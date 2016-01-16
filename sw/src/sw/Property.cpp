#include "Property.h"

namespace sw {

	template <typename T>
	Property<T>::Property() {}

	template <typename T>
	Property<T>::Property(const T& value) {
		m_Value = value;
	}

	template <typename T>
	void Property<T>::operator=(const T& value) {
		m_Value = value;
	}

}

