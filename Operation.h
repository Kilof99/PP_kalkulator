#pragma once
#include "Expression.h"
class Operation : public Expression
{
public:
	Expression* left;
	Expression* right;
	Operation(Expression *l, Expression *r);
};

