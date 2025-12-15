#pragma once
#include "Operation.h"
class Subtract : public Operation
{
public:
	virtual double value();
	virtual Expression* derivative();
	Subtract(Expression* l, Expression* r);
	Subtract(Subtract* origin);
};

