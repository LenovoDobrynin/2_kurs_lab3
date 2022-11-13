#pragma once
#include <string>

class ICallable {
	virtual void call(const std::string& recepient, int callDuration) = 0;
};