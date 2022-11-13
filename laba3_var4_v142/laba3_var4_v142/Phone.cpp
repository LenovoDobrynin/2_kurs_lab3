#include "Phone.h"
#include <string>
#include <fstream>
#include <iostream>

Phone::Phone() {
	model = number = lastCalledNumber = "";
	balance = 0.0;
	battery = 0;
}

Phone::Phone(std::string _model, std::string _number, std::string _lastCalledNumber, double _balance, int _battery) {
	model = _model;
	number = _number;
	lastCalledNumber = _lastCalledNumber;
	balance = _balance;
	battery = _battery;
}

Phone::~Phone() {
	delete this;
}


void Phone::setModel(const std::string _model) {
	model = _model;
}

void Phone::setNumber(const std::string _number) {
	number = _number;
}

void Phone::setLastCalledNumber(const std::string _number) {
	lastCalledNumber = _number;
}

void Phone::setBalance(double _amount) {
	balance = _amount;
}

void Phone::setBattery(int charge) {
	battery = charge;
}



std::string Phone::getModel() {
	return this->model;
}

std::string Phone::getNumber() {
	return this->number;
}

std::string Phone::getLastCalledNumber() {
	return this->lastCalledNumber;
}

double Phone::getBalance() {
	return this->balance;
}

int Phone::getBattery() {
	return this->battery;
}



void Phone::call(const std::string& recepient, int callDuration) {

}


void Phone::serialize() {
	std::string path = "serialize_without_params.txt";
	serialize(path);
}

void Phone::deserialize() {
	std::string path = "serialize_without_params.txt";
	deserialize(path);
}


void Phone::serialize(const std::string filename) {
	std::ofstream fout;
	fout.open(filename);
	if (fout.is_open()) {
		fout << std::endl;
		fout << "Модель: " << this->getModel() << std::endl;
		fout << "Номер: " << this->getNumber() << std::endl;
		fout << "Последний набранный номер: " << this->getLastCalledNumber() << std::endl;
		fout << "Баланс: " << this->getBalance() << std::endl;
		fout << "Заряд: " << this->getBattery() << std::endl;

		std::cout << "Данные успешно сериализованны!" << std::endl;
	}
	fout.close();

}

void Phone::deserialize(const std::string filename) {
	std::ifstream fin;
	fin.open(filename);
	if (fin.is_open()) {
		std::string line;
		std::cout << "Десериализованные данные: " << std::endl;

		while (std::getline(fin, line)) {
			std::cout << line << std::endl;
		}
	}
	fin.close();
}
