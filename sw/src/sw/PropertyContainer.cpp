#include "PropertyContainer.h"

namespace sw {

	PropertyContainer::PropertyContainer()
	{
	}


	PropertyContainer::~PropertyContainer()
	{
	}

	void* PropertyContainer::tryGetValue(AttachedPropertyBase* property) {
		auto it = std::find(m_Values.begin(), m_Values.end(), property);
		if (it == m_Values.end()) {
			return nullptr;
		}
		else {
			return it->second;
		}
	}

}