#pragma once

#include <map>

#include "AttachedPropertyBase.h"
#include "AttachedProperty.h"

namespace sw {

	template<typename T>
	class AttachedProperty;

	class PropertyContainer
	{
	public:
		typedef std::map<
			const AttachedPropertyBase*,
			void*>
			T_ValueMap;

	private:
		T_ValueMap m_Values;

	public:
		PropertyContainer();
		virtual ~PropertyContainer();

		void* tryGetValue(const AttachedPropertyBase* property) const;

		template<typename T>
		void setProperty(const AttachedProperty<T>* property, T value) {
			// Values are stored in heap so they can be converted to void*
			const AttachedPropertyBase* base = static_cast<const AttachedPropertyBase*>(property);

			// Delete previous value to prevent memory leaks
			delete m_Values[base];

			void* val = (void*)new T(value);

			m_Values[base] = val;
		}
	};

}