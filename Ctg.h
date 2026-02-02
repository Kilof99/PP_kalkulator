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

class Ctg : public Function
{
public:
	double value();
	Expression* derivative();
	Ctg* copy();
	std::string toString();
	Ctg(Expression* arg);
	Ctg(Ctg* origin);
};