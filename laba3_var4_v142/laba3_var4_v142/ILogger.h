#pragma once
#include <string>

class ILogger {
public:
	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& filename) = 0;
};