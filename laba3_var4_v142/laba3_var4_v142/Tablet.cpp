#include "Tablet.h"
#include <string>
#include <iostream>

Tablet::Tablet() {
	model = number = lastCalledNumber = "";
	battery = 0;
}

Tablet::Tablet(std::string _model, std::string _number, std::string _lastCalledNumber, int _battery) {
	model = _model;
	number = _number;
	lastCalledNumber = _lastCalledNumber;
	battery = _battery;
}

Tablet::~Tablet() {
	delete this;
}

void Tablet::setModel(std::string _model) {
	model = _model;
}
void Tablet::setNumber(std::string _number) {
	number = _number;
}
void Tablet::setLastCalledNumber(std::string _lastCalledNumber) {
	lastCalledNumber = _lastCalledNumber;
}
void Tablet::setBattery(int _charge) {
	battery = _charge;
}

std::string Tablet::getModel() {
	return this->model;
}
std::string Tablet::getNumber() {
	return this->number;
}
std::string Tablet::getLastCalledNumber() {
	return this->lastCalledNumber;
}
int Tablet::getBattery() {
	return this->battery;
}

void Tablet::call(const std::string recepient) {
	if (this->getBattery() - 10 < 0) {
		std::cout << "Недостаточно заряда батареи для совершения звонка! Необходимо как минимум 10%!" << std::endl;
		return;
	}
	this->setBattery(this->getBattery() - 10);
	this->setLastCalledNumber(recepient);
	std::cout << "Звонок по номеру (" << recepient << ") успешно совершен!\n\n";
}

void Tablet::PrettyPrint() {
	std::cout << "Планшет:\n";
	std::cout << "Модель: " << this->getModel() << std::endl;
	std::cout << "Номер: " << this->getNumber() << std::endl;
	std::cout << "Последний набранный номер: " << this->getLastCalledNumber() << std::endl;
	std::cout << "Заряд: " << this->getBattery() << std::endl << std::endl;
}

void Tablet::serialize() {
	serialize("Tablet.txt");
}
void Tablet::deserialize() {
	deserialize("Tablet.txt");
}

void Tablet::serialize(const std::string filename) {

}
void Tablet::deserialize(const std::string filename) {

}