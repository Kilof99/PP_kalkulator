#pragma once
#include "Function.h"
#include <string>

class Ln : public Function
{
public:
	double value();
	Expression* derivative();
	Ln* copy();
	std::string toString();
	Ln(Expression* arg);
	Ln(Ln* origin);
};