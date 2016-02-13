#pragma once

#include <vector>
#include <functional>

namespace sw {

	template<typename T>
	class Event {
	public:
		typedef T T_EventArgs;
		typedef std::function<void (T_EventArgs)> T_EventHandler;

	private:
		std::vector<T_EventHandler> m_Handlers;

	public:
		Event();
		~Event();

		void addHandler(T_EventHandler handler);
		void removeHandler(T_EventHandler handler);

		void raiseEvent(T_EventArgs args);
	};

}