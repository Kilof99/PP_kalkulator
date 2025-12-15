#pragma once
#include "Operation.h"
class Subtract : public Operation
{
public:
	double value();
	Expression* derivative();
	Subtract* copy();
	Subtract(Expression* l, Expression* r);
	Subtract(Subtract* origin);
};

