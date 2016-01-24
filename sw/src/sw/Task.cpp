#include "Task.h"

namespace sw {

	void Task::schedule(Dispatcher* dispatcher) {
		if (m_State == TaskState::NotScheduled) {
			dispatcher->schedule(this);
			m_Dispatcher = dispatcher;
			if (m_Awaiting.size() == 0) {
				m_State = TaskState::Scheduled;
			} else {
				m_State = TaskState::Awaiting;
			}
		}
	}

	void Task::execute() {
		if(m_State != TaskState::Running) {
			m_State = TaskState::Running;
			this->run();
			m_State = TaskState::NotScheduled;
			for (auto it = m_AwaitingThis.begin(); it != m_Awaiting.end(); it++) {
				(*it)->finishAwaiting(this);
			}
		}
	}

	void Task::awaitFor(Task* task) {
		if (std::find(m_Awaiting.begin(), m_Awaiting.end(), task) == m_Awaiting.end()) {
			m_Awaiting.push_back(task);
			task->addAwaitable(this);
			if(m_State == TaskState::Scheduled) {
				m_State = TaskState::Awaiting;
			}
		}
	}

	void Task::addAwaitable(Task* task) {
		m_AwaitingThis.push_back(task);
	}

	void Task::finishAwaiting(Task* task) {
		auto it = std::find(m_Awaiting.begin(), m_Awaiting.end(), task);
		if(it != m_Awaiting.end()) {
			m_Awaiting.erase(it);
			if(m_Awaiting.size() == 0 && m_State == TaskState::Awaiting) {
				m_State = TaskState::Scheduled;
			}
		}
	}
}
