#pragma once
#include "Operation.h"
class Multiply : public Operation
{
public:
	virtual double value();
	virtual Expression* derivative();
	Multiply(Expression* l, Expression* r);
	Multiply(Multiply* origin);
};

