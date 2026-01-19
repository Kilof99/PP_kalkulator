#pragma once
#include "Expression.h"
class Variable : public Expression
{
public:
	double value();
	Expression* derivative();
	Variable* copy();
	static double x;

	Variable();
};

