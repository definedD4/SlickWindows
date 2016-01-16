#pragma once

#include <iostream>

#include "Dispatcher.h"

namespace sw {

	enum class TaskState {
		NotScheduled,
		Scheduled,
		Awaiting,
		Running
	};

	class Dispatcher;

	class Task {
	private:
		int m_Priority = 0;

		TaskState m_State = TaskState::NotScheduled;
		Dispatcher* m_Dispatcher = nullptr;

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

		friend class Dispatcher;
	};

}