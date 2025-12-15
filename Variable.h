#pragma once
#include "Expression.h"
class Variable : public Expression
{
public:
	double value();
	Expression* derivative();
	static double x;
};

