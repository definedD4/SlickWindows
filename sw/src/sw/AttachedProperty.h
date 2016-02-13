#pragma once

#include <string>

#include "AttachedPropertyBase.h"
#include "PropertyContainer.h"

namespace sw {

	template<typename T>
	class AttachedProperty : public virtual AttachedPropertyBase
	{
	public:
		typedef T T_ValueType;

	private:
		T_ValueType m_DefaultValue;

	public:
		AttachedProperty(std::string name) : AttachedPropertyBase(name) {

		}

		virtual ~AttachedProperty() {

		}

		T_ValueType getValue(PropertyContainer* object) {
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
