#include "CustomExpressionEvaluator.h"
#include <fstream>
#include <iostream>
#include <strstream>

CustomExpressionEvaluator::CustomExpressionEvaluator(int elemetsCount) : ExpressionEvaluator(elemetsCount) { }

double CustomExpressionEvaluator::Calculate() {
	double res = 0.0;
	for (size_t counter = 0; counter < operandsCount; counter++) {
		res += (counter + 1) * Operands[counter];
	}
	return res;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) {
	std::ofstream fout;
	fout.open(filename, std::ios::app);
	if (fout.is_open()) {

		fout << std::endl << "Total: " << operandsCount << std::endl;
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
					fout << counter + 1 << "*" << Operands[counter];
				}
				else {
					fout << counter + 1 << "*(" << Operands[counter] << ")";
				}
			}

			if (counter != operandsCount - 1) {
				fout << " + ";
			}
		}
		fout << std::endl << "-> " << this->Calculate();
		std::cout << "Результат был записан в файл!" << std::endl;
	}
	fout.close();
}

void CustomExpressionEvaluator::logToScreen() {
	std::cout << "Total: " << operandsCount << std::endl;
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
				std::cout << counter + 1 << "*" << Operands[counter];

			}
			else {
				std::cout << counter + 1 << "*(" << Operands[counter] << ")";

			}
		}

		if (counter != operandsCount - 1) {
			std::cout << " + ";
		}
	}
	std::cout << std::endl << "-> " << this->Calculate() << std::endl;
}


bool CustomExpressionEvaluator::isPositive(double number) {
	if (number > 0) {
		return true;
	}
	else {
		return false;
	}
}

void CustomExpressionEvaluator::shuffle(int left, int right) {
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

void CustomExpressionEvaluator::shuffle() {
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