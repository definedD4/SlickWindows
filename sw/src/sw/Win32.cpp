#include "Win32.h"

#include "Windows.h"

void setConsoleTextAttributes(WORD attributes) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, attributes);
}