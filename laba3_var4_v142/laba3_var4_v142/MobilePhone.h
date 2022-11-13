#pragma once
#include "Phone.h"
class MobilePhone : public Phone
{
public:
	MobilePhone();
	MobilePhone(std::string _model, std::string _number, std::string _lastCalledNumber, double _balance, int battery);

	void call(const std::string number, int calDuration);
	bool isDigitOnly(std::string str);

	void PrettyPrint();

	~MobilePhone();
};

