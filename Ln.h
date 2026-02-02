/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Function.h"
#include <string>

class Ln : public Function
{
public:
	double value();
	Expression* derivative();
	Ln* copy();
	std::string toString();
	Ln(Expression* arg);
	Ln(Ln* origin);
};