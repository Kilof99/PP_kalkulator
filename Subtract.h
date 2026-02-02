/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Operation.h"
class Subtract : public Operation
{
public:
	double value();
	Expression* derivative();
	Subtract* copy();
	std::string toString();
	Subtract(Expression* l, Expression* r);
	Subtract(Subtract* origin);
	virtual ~Subtract() = default;
};

