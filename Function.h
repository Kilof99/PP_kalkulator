#pragma once
#include "Expression.h"

class Function : public Expression
{
public:
	Expression* argument;

	Function(Expression* arg);
	Function(Function* origin);
	virtual ~Function() = default;
};

