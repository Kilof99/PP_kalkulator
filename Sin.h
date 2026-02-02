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

class Sin : public Function
{
public:
	double value();
	Expression* derivative();
	Sin* copy();
	std::string toString();
	Sin(Expression* arg);
	Sin(Sin* origin);
};