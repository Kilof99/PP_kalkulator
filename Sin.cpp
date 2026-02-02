/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Sin.h"
#include <cmath>
#include "Multiply.h"
#include "Cos.h"
#include "Constant.h"

Sin::Sin(Expression* arg) : Function(arg) {}
Sin::Sin(Sin* origin) : Function(origin) {}

double Sin::value() {
	return std::sin(argument->value());
}

Expression* Sin::derivative() {
	// d/dx sin(u) = cos(u) * u'
	return new Multiply(argument->derivative(), new Cos(argument->copy()));
}

Sin* Sin::copy() {
	return new Sin(this);
}

std::string Sin::toString() {
	return "sin(" + argument->toString() + ")";
}