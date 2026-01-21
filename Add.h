#pragma once
#include "Operation.h"
class Add : public Operation
{
public:
	double value();
	Expression* derivative();
	Add* copy();
	std::string toString();
	Add(Expression *l, Expression *r);
	Add(Add* origin);
};

