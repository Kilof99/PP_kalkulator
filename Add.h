/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Operation.h"
class Add : public Operation
{
public:
	double value();
	Expression* derivative();
	Add* copy();
	std::string toString();
	Add(Expression *l, Expression *r);
	Add(Add* origin);
	virtual ~Add() = default;
};

