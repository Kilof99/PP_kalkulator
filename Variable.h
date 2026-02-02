/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Expression.h"
class Variable : public Expression
{
public:
	double value();
	Expression* derivative();
	Variable* copy();
	std::string toString();
	static double x;

	Variable();
	virtual ~Variable() = default;
};

