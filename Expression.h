#pragma once
#include <string>

class Expression
{
public:
	virtual double value() = 0;
	virtual Expression* derivative() = 0;
	virtual Expression* copy() = 0;
	virtual std::string toString() = 0;
};
