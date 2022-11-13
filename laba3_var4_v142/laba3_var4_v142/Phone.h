#pragma once
#include "ICallable.h"
#include <string>

class Phone : public ICallable
{
private:
	std::string model;
	std::string number;
	std::string lastCalledNumber;
	double balance;
	int battery;
public:
	Phone();
	Phone(std::string _model, std::string number, std::string stringlastCalledNumber, double balance, int battery);
	~Phone();

	void setModel(const std::string model);
	void setNumber(const std::string number);
	void setLastCalledNumber(const std::string number);
	void setBalance(double amount);
	void setBattery(int charge);

	std::string getModel();
	std::string getNumber();
	std::string getLastCalledNumber();
	double getBalance();
	int getBattery();

	virtual void call(const std::string& recepient, int callDuration);


	void serialize();
	void deserialize();

	void serialize(const std::string filename);
	void deserialize(const std::string filename);
};

