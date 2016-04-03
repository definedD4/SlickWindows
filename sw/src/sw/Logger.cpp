#include "Logger.h"

using namespace std;

namespace sw {

	Logger Logger::s_Instance;

	std::ostream& Logger::streamLog(LogLevel level) {
		setConsoleTextAttributes(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "SW INFO: ";
		return cout;
	}

	Logger::Logger() { }

	Logger::~Logger() { }

	void Logger::log(LogLevel level, const std::string& message) {
		switch(level) {
		case LogLevel::Info: 
			setConsoleTextAttributes(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "SW INFO: " << message << endl;
			break;
		case LogLevel::Warning:
			setConsoleTextAttributes(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "SW WARNING: " << message << endl;
			break;
		case LogLevel::Error:
			setConsoleTextAttributes(FOREGROUND_RED);
			cout << "SW ERROR: " << message << endl;
			break;
		case LogLevel::Fatal:
			setConsoleTextAttributes(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << "SW FATAL: " << message << endl;
			break;
		}
	}

}

