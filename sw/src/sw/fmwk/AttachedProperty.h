#pragma once

#include <string>

#include "AttachedPropertyBase.h"
#include "PropertyContainer.h"

namespace sw {

	class PropertyContainer;

	template<typename T>
	class AttachedProperty : public virtual AttachedPropertyBase
	{
	public:
		typedef T T_ValueType;

	private:
		T_ValueType m_DefaultValue;

	public:
		AttachedProperty(std::string name, T_ValueType defaultValue)
			: AttachedPropertyBase(name), m_DefaultValue(defaultValue) {

		}

		virtual ~AttachedProperty() {

		}

		T_ValueType getValue(PropertyContainer* object) const {
			void* res = object->tryGetValue(this);
			if (res == 0) {
				return m_DefaultValue;
			}
			else {
				return *((T_ValueType*)res);
			}
		}
	};

}
