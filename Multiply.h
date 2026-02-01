#pragma once
#include "Operation.h"
class Multiply : public Operation
{
public:
	double value();
	Expression* derivative();
	Multiply* copy();
	std::string toString();
	Multiply(Expression* l, Expression* r);
	Multiply(Multiply* origin);
	virtual ~Multiply() = default;
};

