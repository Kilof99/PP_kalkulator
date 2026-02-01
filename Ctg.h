#pragma once
#include "Function.h"
#include <string>

class Ctg : public Function
{
public:
	double value();
	Expression* derivative();
	Ctg* copy();
	std::string toString();
	Ctg(Expression* arg);
	Ctg(Ctg* origin);
};