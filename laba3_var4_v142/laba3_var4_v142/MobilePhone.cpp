#include "MobilePhone.h"
#include <algorithm>
#include <iostream>

MobilePhone::MobilePhone() : Phone("", "", "", 0.0, 0) { }

MobilePhone::MobilePhone(std::string model, std::string number, std::string lastCalledNumber, double balance, int battery)
	: Phone(model, number, lastCalledNumber, balance, battery) { }


void MobilePhone::call(const std::string number, int callDuration) {
	if (!isDigitOnly(number)) {
		std::cout << "�������� �����! �� �������� �� ������ �����!" << std::endl;
		return;
	}
	else {
		if (this->getBattery() <= 0 || (this->getBattery() - callDuration * 3) < 0) { // ���� ����� 0, ��� ����� ������ ��������� ������ 0
			std::cout << "������������ ������ ������� ��� ���������� ������! ��� �����: " << this->getBattery() << std::endl;
			return;
		}
		if (this->getBalance() < 0) { // ���� �� ����� ������������� ������
			std::cout << "������������ ������� ��� ���������� ������. ��� ������: " << this->getBalance() << std::endl;
			return;
		}
		this->setBalance(this->getBalance() - callDuration * 0.5);
		this->setBattery(this->getBattery() - callDuration * 3);
		this->setLastCalledNumber(number);
		std::cout << "������ �� ������ (" << number << ") �������� �������!" << std::endl << std::endl;
	}
}

bool MobilePhone::isDigitOnly(std::string str) {
	return std::all_of(str.begin(), str.end(), ::isdigit);
}



MobilePhone::~MobilePhone() {
	delete this;
}


void MobilePhone::PrettyPrint() {
	std::cout << "��������� �������:\n";
	std::cout << "������: " << this->getModel() << std::endl;
	std::cout << "�����: " << this->getNumber() << std::endl;
	std::cout << "��������� ��������� �����: " << this->getLastCalledNumber() << std::endl;
	std::cout << "������: " << this->getBalance() << std::endl;
	std::cout << "�����: " << this->getBattery() << std::endl << std::endl << std::endl;
}