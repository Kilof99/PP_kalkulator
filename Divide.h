#pragma once
#include "Operation.h"
class Divide : public Operation
{
public:
	double value();
	Expression* derivative();
	Divide* copy();
	std::string toString();
	Divide(Expression* l, Expression* r);
	Divide(Divide* origin);
};

