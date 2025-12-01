#pragma once
class Expression
{
public:
	virtual double value() = 0;
	virtual Expression* derivative() = 0;
};
