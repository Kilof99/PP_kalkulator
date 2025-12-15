#pragma once
#include "Expression.h"
class Constant : public Expression
{
public:
	double value();
	Expression* derivative();
	Constant* copy();
	double number;

	Constant(double value);
};

