#include "PropertyContainer.h"

namespace sw {

	PropertyContainer::PropertyContainer()
	{
	}


	PropertyContainer::~PropertyContainer()
	{
	}

	void* PropertyContainer::tryGetValue(const AttachedPropertyBase* property) const {
		auto it = m_Values.find(property);
		if (it == m_Values.end()) {
			return nullptr;
		}
		else {
			return it->second;
		}
	}

}