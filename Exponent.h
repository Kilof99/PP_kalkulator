/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Operation.h"
class Exponent : public Operation
{
public:
	double value();
	Expression* derivative();
	Exponent* copy();
	std::string toString();
	Exponent(Expression* l, Expression* r);
	Exponent(Exponent* origin);
	virtual ~Exponent() = default;
};

