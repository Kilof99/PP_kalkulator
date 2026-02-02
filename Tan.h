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

class Tan : public Function
{
public:
	double value();
	Expression* derivative();
	Tan* copy();
	std::string toString();
	Tan(Expression* arg);
	Tan(Tan* origin);
};