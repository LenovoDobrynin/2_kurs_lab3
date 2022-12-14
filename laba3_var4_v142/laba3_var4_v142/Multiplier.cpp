#include "Multiplier.h"
#include <fstream>
#include <iostream>

Multiplier::Multiplier(int elemCount) : ExpressionEvaluator(elemCount) { }

double Multiplier::Calculate() {
	double res = 1.0;
	for (size_t counter = 0; counter < operandsCount; counter++) {
		res *= Operands[counter];
	}
	return res;
}

void Multiplier::logToFile(const std::string& filename) {
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
				fout << " * ";
			}
		}
		fout << "\n-> " << this->Calculate();
	}
	fout.close();
	std::cout << "\n????????? ??????? ? ????!\n";
}


void Multiplier::logToScreen() {
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
			std::cout << " * ";
		}
	}
	std::cout << "\n-> " << this->Calculate();
}


bool Multiplier::isPositive(double number) {
	if (number > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Multiplier::shuffle(int left, int right) {
	// ????????????? ??? ???????? ????? left ? right
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

void Multiplier::shuffle() {
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