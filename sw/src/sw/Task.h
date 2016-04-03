#pragma once

#include "Common.h"
#include "Dispatcher.h"

namespace sw {

	class Dispatcher;

	enum class TaskState {
		NotScheduled,
		Scheduled,
		Awaiting,
		Running
	};

	class Task {
	private:
		int m_Priority = 0;

		TaskState m_State = TaskState::NotScheduled;
		Dispatcher* m_Dispatcher = nullptr;

		std::vector<Task*> m_AwaitingThis;
		std::vector<Task*> m_Awaiting;

		void addAwaitable(Task* task);
		void finishAwaiting(Task* task);

	protected:
		void setPriority(int value) { m_Priority = value; }
		void execute();

	public:
		virtual ~Task() {}

		int getPriority() const { return m_Priority; };
		TaskState getState() const { return m_State; }
		Dispatcher* getDispatcher() const { return m_Dispatcher; }

		void schedule(Dispatcher* dispatcher);
		virtual void run() = 0;

		void awaitFor(Task* task);

		friend class Dispatcher;
	};

}