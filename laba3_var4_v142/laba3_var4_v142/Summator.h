#pragma once
#include "ExpressionEvaluator.h"
#include <string>

class Summator : public ExpressionEvaluator
{
public:
	Summator();
	Summator(int _operandsCount);

	double Calculate();
	bool isPositive(double number);

	void logToFile(const std::string& filename);
	void logToScreen();

	void shuffle();
	void shuffle(int left, int right);
};

