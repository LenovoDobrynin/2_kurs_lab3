#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() {
	operandsCount = 20;
	Operands = new double[operandsCount];
	for (size_t counter = 0; counter < operandsCount; counter++) {
		Operands[counter] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int count) {
	operandsCount = count;
	Operands = new double[operandsCount];
	for (size_t counter = 0; counter < operandsCount; counter++) {
		Operands[counter] = 0;
	}
}

void ExpressionEvaluator::logToScreen()
{
}

void ExpressionEvaluator::logToFile(std::string& filename)
{
}

void ExpressionEvaluator::setOneOperand(double operand, int position) {
	Operands[position] = operand;
}

void ExpressionEvaluator::setManyOperands(double* _operands, int _operandsCount) {
	operandsCount = _operandsCount;
	Operands = new double[operandsCount];
	for (size_t counter = 0; counter < operandsCount; counter++) {
		Operands[counter] = _operands[counter];
	}
}


ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] Operands;
}