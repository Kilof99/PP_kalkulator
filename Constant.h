#pragma once
#include "Expression.h"
class Constant : public Expression
{
public:
	double value();
	Expression* derivative();
	Constant* copy();
	std::string toString();
	double number;

	Constant(double value);
	virtual ~Constant() = default;
};

