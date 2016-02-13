#include "PropertyContainer.h"

namespace sw {

	PropertyContainer::PropertyContainer()
	{
	}


	PropertyContainer::~PropertyContainer()
	{
	}

	void* PropertyContainer::tryGetValue(AttachedPropertyBase* property) {
		auto it = m_Values.find(property);
		if (it == m_Values.end()) {
			return nullptr;
		}
		else {
			return it->second;
		}
	}

}