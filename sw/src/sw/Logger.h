#pragma once

#include <string>
#include <iostream>

#include "Common.h"
#include "Win32.h"

namespace sw {

	Logger* logger();
	void destroyLogger();

	enum class LogLevel {
		Info,
		Warning,
		Error,
		Fatal
	};

	class Logger {
	private:
		static Logger* s_Instance;
	public:
		static Logger* current() {
			if (!s_Instance) {
				s_Instance = new Logger();
			}
			return s_Instance;
		}

		void log(LogLevel level, const std::string& message);
		void logInfo(const std::string& message) { log(LogLevel::Info, message); }
		void logWarning(const std::string& message) { log(LogLevel::Warning, message); }
		void logError(const std::string& message) { log(LogLevel::Error, message); }
		void logFatal(const std::string& message) { log(LogLevel::Fatal, message); }

	private:
		Logger();
		~Logger();

		friend void destroyLogger();
	};

	inline Logger* logger() { return Logger::current(); }


}

