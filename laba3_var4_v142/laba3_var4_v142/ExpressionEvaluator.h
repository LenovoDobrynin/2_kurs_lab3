#pragma once
#include "ILogger.h"
#include "IShuffle.h"

class ExpressionEvaluator : public ILogger, public IShuffle
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int count);

	void logToScreen();
	void logToFile(std::string& filename);

	void setOneOperand(double operand, int position);
	void setManyOperands(double* operands, int operandsCount);

	virtual double Calculate() = 0;

	virtual ~ExpressionEvaluator() = 0;

	double* Operands;
	int operandsCount;
};

