#include "MobilePhone.h"
#include <algorithm>
#include <iostream>

MobilePhone::MobilePhone() : Phone("", "", "", 0.0, 0) { }

MobilePhone::MobilePhone(std::string model, std::string number, std::string lastCalledNumber, double balance, int battery)
	: Phone(model, number, lastCalledNumber, balance, battery) { }


void MobilePhone::call(const std::string number, int callDuration) {
	if (!isDigitOnly(number)) {
		std::cout << "Неверный номер! Он содержит не только цифры!" << std::endl;
		return;
	}
	else {
		if (this->getBattery() <= 0 || (this->getBattery() - callDuration * 3) < 0) { // если заряд 0, или после звонка останется меньше 0
			std::cout << "Недостаточно заряда батареи для совершения звонка! Ваш заряд: " << this->getBattery() << std::endl;
			return;
		}
		if (this->getBalance() < 0) { // если на счету отрицательный баланс
			std::cout << "Недостаточно средств для совершения звонка. Ваш баланс: " << this->getBalance() << std::endl;
			return;
		}
		this->setBalance(this->getBalance() - callDuration * 0.5);
		this->setBattery(this->getBattery() - callDuration * 3);
		this->setLastCalledNumber(number);
		std::cout << "Звонок по номеру (" << number << ") завершен успешно!" << std::endl << std::endl;
	}
}

bool MobilePhone::isDigitOnly(std::string str) {
	return std::all_of(str.begin(), str.end(), ::isdigit);
}



MobilePhone::~MobilePhone() {
	delete this;
}


void MobilePhone::PrettyPrint() {
	std::cout << "Мобильный телефон:\n";
	std::cout << "Модель: " << this->getModel() << std::endl;
	std::cout << "Номер: " << this->getNumber() << std::endl;
	std::cout << "Последний набранный номер: " << this->getLastCalledNumber() << std::endl;
	std::cout << "Баланс: " << this->getBalance() << std::endl;
	std::cout << "Заряд: " << this->getBattery() << std::endl << std::endl << std::endl;
}