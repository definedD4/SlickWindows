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
		Event() { }
		~Event() { }

		void addHandler(T_EventHandler handler) {
			m_Handlers.push_back(handler);
		}

		void removeHandler(T_EventHandler handler) {
			handler.erase(std::remove(handler.begin(), handler.end(), handler), handler.end());
		}

		void raiseEvent(T_EventArgs args) {
			for (T_EventHandler handler : m_Handlers) {
				handler(args);
			}
		}
	};

}