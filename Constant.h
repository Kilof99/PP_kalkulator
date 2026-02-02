/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Expression.h"
class Constant : public Expression
{
public:
	double value();
	Expression* derivative();
	Constant* copy();
	std::string toString();
	double number;

	Constant(double value);
	virtual ~Constant() = default;
};

