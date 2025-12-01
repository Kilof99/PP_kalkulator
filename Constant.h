#pragma once
#include "Expression.h"
class Constant : public Expression
{
public:
	virtual double value();
	virtual Expression* derivative();
	double number;

	Constant(double value);
};

