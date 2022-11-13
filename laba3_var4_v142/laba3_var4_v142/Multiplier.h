#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier(int operandsCount);
	double Calculate();

	void logToScreen();
	void logToFile(const std::string& filename);

	bool isPositive(double number);

	void shuffle();
	void shuffle(int left, int right);
};

