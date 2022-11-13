#pragma once
#include <string>
#include "ExpressionEvaluator.h"

class CustomExpressionEvaluator : public ExpressionEvaluator
{
public:
	CustomExpressionEvaluator(int elementsCount);

	double Calculate();
	bool isPositive(double number);

	void logToFile(const std::string& filename);
	void logToScreen();
	void shuffle();
	void shuffle(int left, int right);
};

