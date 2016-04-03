#include "Dispatcher.h"

namespace sw {

	bool Dispatcher::task_comparer::operator()(const Task* t1, const Task* t2) const {
		return t1->getPriority() < t2->getPriority();
	}

	Dispatcher::Dispatcher() {
		
	}

	Dispatcher::~Dispatcher() {
		
	}

	void Dispatcher::schedule(Task* task) {
		m_TaskQueue.push(task);
	}

	void Dispatcher::process(int count) {
		for (int i = 0; i < count || count == 0; i++) {
			if (m_TaskQueue.size() <= 0)
				break;

			Task* t = m_TaskQueue.top();
			t->execute();
			m_TaskQueue.pop();
		}
	}
}
