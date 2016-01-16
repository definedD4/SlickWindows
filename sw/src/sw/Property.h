#pragma once
#include <ostream>

namespace sw {

	template<typename T>
	class Property {
	public:
		typedef T ValueType;
	private:
		T& m_Value;
	public:
		Property();
		Property(const T& value);

		T& get() const { return m_Value; }
		void set(const T& value) { m_Value = value; }

		void operator = (const T& value);
		operator T&() const { return get(); }
		T& operator()() const { return get(); }
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& stream, Property<T>& property);

}
