#pragma once
#include "Function.h"
#include <string>

class Tan : public Function
{
public:
	double value();
	Expression* derivative();
	Tan* copy();
	std::string toString();
	Tan(Expression* a);
	Tan(Tan* origin);
};