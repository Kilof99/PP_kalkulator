#pragma once
#include "Operation.h"
class Exponent : public Operation
{
public:
	double value();
	Expression* derivative();
	Exponent* copy();
	std::string toString();
	Exponent(Expression* l, Expression* r);
	Exponent(Exponent* origin);
};

