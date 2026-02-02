/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include "Function.h"
#include <string>

class Cos : public Function
{
public:
	double value();
	Expression* derivative();
	Cos* copy();
	std::string toString();
	Cos(Expression* arg);
	Cos(Cos* origin);
};