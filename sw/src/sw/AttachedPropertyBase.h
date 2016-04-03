#pragma once

#include <string>

namespace sw {

	class AttachedPropertyBase
	{
	private:
		std::string m_Name;

	public:
		AttachedPropertyBase(std::string name) : m_Name(name) {

		}

		virtual ~AttachedPropertyBase() {

		}
		
		std::string getName() const { return m_Name; }

		bool operator==(const AttachedPropertyBase &other) const
		{
			return m_Name == other.m_Name;
		}

	};

	struct AttachedPropertyHasher
	{
		std::size_t operator()(const AttachedPropertyBase& k) const
		{
			return std::hash<std::string>()(k.getName());
		}
	};

	struct AttachedPropertyComparer
	{
		bool operator()(const AttachedPropertyBase& a, const AttachedPropertyBase& b)
		{
			return a.getName() == b.getName();
		}
	};

}