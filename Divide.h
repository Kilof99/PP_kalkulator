/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Operation.h"
class Divide : public Operation
{
public:
	double value();
	Expression* derivative();
	Divide* copy();
	std::string toString();
	Divide(Expression* l, Expression* r);
	Divide(Divide* origin);
	virtual ~Divide() = default;
};

