#include "Summator.h"
#include <iostream>
#include <fstream>

Summator::Summator() : ExpressionEvaluator() { }

Summator::Summator(int _operandsCount) {
	operandsCount = _operandsCount;
}

double Summator::Calculate() {
	double res = 0.0;
	for (size_t counter = 0; counter < operandsCount; counter++) {
		res += Operands[counter];
	}
	return res;
}

void Summator::logToFile(const std::string& filename) {
	std::ofstream fout;
	fout.open(filename, std::ios::app);
	if (fout.is_open()) {
		fout << "\nTotal: " << operandsCount << std::endl;
		for (size_t counter = 0; counter < operandsCount; counter++) {
			if (counter == 0) {
				if (isPositive(Operands[counter])) {
					fout << Operands[counter];
				}
				else {
					fout << "(" << Operands[counter] << ")";
				}
			}
			else {
				if (isPositive(Operands[counter])) {
					fout << Operands[counter];
				}
				else {
					fout << "(" << Operands[counter] << ")";
				}
			}
			if (counter != operandsCount - 1) {
				fout << " + ";
			}
		}
		fout << "\n-> " << this->Calculate();
	}
	fout.close();
	std::cout << "\nЦезультат записан в файл!\n";
}


void Summator::logToScreen() {
	std::cout << "\nTotal: " << operandsCount << std::endl;
	for (size_t counter = 0; counter < operandsCount; counter++) {
		if (counter == 0) {
			if (isPositive(Operands[counter])) {
				std::cout << Operands[counter];
			}
			else {
				std::cout << "(" << Operands[counter] << ")";
			}
		}
		else {
			if (isPositive(Operands[counter])) {
				std::cout << Operands[counter];
			}
			else {
				std::cout << "(" << Operands[counter] << ")";
			}
		}
		if (counter != operandsCount - 1) {
			std::cout << " + ";
		}
	}
	std::cout << "\n-> " << this->Calculate();
}


bool Summator::isPositive(double number) {
	if (number > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Summator::shuffle(int left, int right) {
	// отсортировать все операнды между left и right
	double temp = 0.0;
	for (size_t counter = left; counter <= right; counter++) {
		for (size_t nextCounter = left + 1; nextCounter < right; nextCounter++) {
			if (Operands[counter] < Operands[nextCounter]) {
				temp = Operands[counter];
				Operands[counter] = Operands[nextCounter];
				Operands[nextCounter] = temp;
			}
		}
	}
}

void Summator::shuffle() {
	double temp = 0.0;
	for (size_t counter = 0; counter < operandsCount; counter++) {
		for (size_t nextCounter = 0; nextCounter < operandsCount; nextCounter++) {
			if (Operands[counter] > Operands[nextCounter]) {
				temp = Operands[counter];
				Operands[counter] = Operands[nextCounter];
				Operands[nextCounter] = temp;
			}
		}
	}
}