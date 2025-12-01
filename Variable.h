#pragma once
#include "Expression.h"
class Variable : public Expression
{
public:
	virtual double value();
	virtual Expression* derivative();
	//static double x;
};

