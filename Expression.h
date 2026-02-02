/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include <string>

class Expression
{
public:
	virtual ~Expression() = default;
	virtual double value() = 0;
	virtual Expression* derivative() = 0;
	virtual Expression* copy() = 0;
	virtual std::string toString() = 0;
};
