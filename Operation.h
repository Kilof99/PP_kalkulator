/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Expression.h"
class Operation : public Expression
{
public:
	Expression* left;
	Expression* right;
	Operation(Expression *l, Expression *r);
	Operation(Operation *origin);
	virtual ~Operation() = default;
};

