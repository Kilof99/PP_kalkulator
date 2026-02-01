#pragma once
#include "Function.h"
#include <string>

class Cos : public Function
{
public:
	double value();
	Expression* derivative();
	Cos* copy();
	std::string toString();
	Cos(Expression* arg);
	Cos(Cos* origin);
};