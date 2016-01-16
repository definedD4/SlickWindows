#include "Task.h"

namespace sw {

	void Task::schedule(Dispatcher* dispatcher) {
		if (m_State == TaskState::NotScheduled) {
			dispatcher->schedule(this);
			m_Dispatcher = dispatcher;
			m_State = TaskState::Scheduled;
		}
	}

	void Task::execute() {
		if(m_State != TaskState::Running) {
			m_State = TaskState::Running;
			this->run();
			m_State = TaskState::NotScheduled;
		}
	}
}
