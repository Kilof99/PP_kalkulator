/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Cos.h"
#include <cmath>
#include "Multiply.h"
#include "Sin.h"
#include "Constant.h"

Cos::Cos(Expression* arg) : Function(arg) {}
Cos::Cos(Cos* origin) : Function(origin) {}

double Cos::value() {
	return std::cos(argument->value());
}

Expression* Cos::derivative() {
	// d/dx cos(u) = -sin(u) * u'
	return new Multiply(argument->derivative(),
		new Multiply(new Constant(-1), new Sin(argument->copy()))
	);
}

Cos* Cos::copy() {
	return new Cos(this);
}

std::string Cos::toString() {
	return "cos(" + argument->toString() + ")";
}