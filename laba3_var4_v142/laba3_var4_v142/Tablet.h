#pragma once
#include <string>
#include "Phone.h"

class Tablet : public Phone
{
private:
	std::string model;
	std::string number;
	std::string lastCalledNumber;
	int battery;
public:
	Tablet();
	Tablet(std::string model, std::string number, std::string lastCalledNumber, int battery);
	~Tablet();

	void setModel(std::string model);
	void setNumber(std::string number);
	void setLastCalledNumber(std::string lastCalledNumber);
	void setBattery(int charge);

	std::string getModel();
	std::string getNumber();
	std::string getLastCalledNumber();
	int getBattery();

	void call(const std::string recepient);
	void PrettyPrint();

	void serialize();
	void deserialize();

	void serialize(const std::string filename);
	void deserialize(const std::string filename);
};

