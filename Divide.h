#pragma once
#include "Operation.h"
class Divide : public Operation
{
public:
	virtual double value();
	virtual Expression* derivative();
	Divide(Expression* l, Expression* r);
	Divide(Divide* origin);
};

