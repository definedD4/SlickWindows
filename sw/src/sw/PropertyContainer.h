#pragma once

#include <map>

#include "AttachedPropertyBase.h"

namespace sw {

	class PropertyContainer
	{
	public:
		typedef std::map<AttachedPropertyBase*, void*> T_ValueMap;

	private:
		T_ValueMap m_Values;

	public:
		PropertyContainer();
		virtual ~PropertyContainer();

		void* tryGetValue(AttachedPropertyBase* property);
	};

}