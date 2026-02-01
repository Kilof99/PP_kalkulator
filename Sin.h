#pragma once
#include "Function.h"
#include <string>

class Sin : public Function
{
public:
	double value();
	Expression* derivative();
	Sin* copy();
	std::string toString();
	Sin(Expression* arg);
	Sin(Sin* origin);
};