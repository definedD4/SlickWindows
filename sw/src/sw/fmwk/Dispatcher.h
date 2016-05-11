#pragma once

#include <queue>

#include "sw/Common.h"
#include "sw/fmwk/Task.h"

namespace sw {

	class Task;

	class Dispatcher {
	private:
		class task_comparer {
		public:
			bool operator()(const Task* t1, const Task* t2) const;
		};

		typedef std::priority_queue <Task*, std::vector<Task*>, task_comparer> TaskQueue;

		TaskQueue m_TaskQueue;

	protected:
		void schedule(Task* task);

	public:
		Dispatcher();
		~Dispatcher();

		void process(int count);

		size_t tasksScheduled() const { return m_TaskQueue.size(); }

		friend class Task;
	};

}
