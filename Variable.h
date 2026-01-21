#pragma once
#include "Expression.h"
class Variable : public Expression
{
public:
	double value();
	Expression* derivative();
	Variable* copy();
	std::string toString();
	static double x;

	Variable();
};

