#pragma once
class Expression
{
public:
	virtual double value() = 0;
	virtual Expression* derivative() = 0;
	virtual Expression* copy() = 0;
};
