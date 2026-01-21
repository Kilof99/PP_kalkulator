#pragma once
#include "Operation.h"
class Subtract : public Operation
{
public:
	double value();
	Expression* derivative();
	Subtract* copy();
	std::string toString();
	Subtract(Expression* l, Expression* r);
	Subtract(Subtract* origin);
};

