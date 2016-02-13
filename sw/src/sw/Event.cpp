#include "Event.h"

namespace sw {

	template<typename T>
	Event<T>::Event() {

	}

	template<typename T>
	Event<T>::~Event() {

	}

	template<typename T>
	void Event<T>::addHandler(T_EventHandler handler) {
		m_Handlers.push_back(handler);
	}

	template<typename T>
	void Event<T>::removeHandler(T_EventHandler handler) {
		handler.erase(std::remove(handler.begin(), handler.end(), handler), handler.end());
	}

	template<typename T>
	void Event<T>::raiseEvent(T_EventArgs args) {
		for (T_EventHandler handler : m_Handlers) {
			handler(args);
		}
	}

}