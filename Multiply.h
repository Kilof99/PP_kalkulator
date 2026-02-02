/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Operation.h"
class Multiply : public Operation
{
public:
	double value();
	Expression* derivative();
	Multiply* copy();
	std::string toString();
	Multiply(Expression* l, Expression* r);
	Multiply(Multiply* origin);
	virtual ~Multiply() = default;
};

