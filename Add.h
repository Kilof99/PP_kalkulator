#pragma once
#include "Operation.h"
class Add : public Operation
{
public:
	virtual double value();
	virtual Expression* derivative();
	Add(Expression *l, Expression *r);
};

