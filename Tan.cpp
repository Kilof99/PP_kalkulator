/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Tan.h"
#include <cmath>
#include "Multiply.h"
#include "Divide.h"
#include "Cos.h"
#include "Constant.h"

Tan::Tan(Expression* arg) : Function(arg) {}
Tan::Tan(Tan* origin) : Function(origin) {}

double Tan::value() {
	return std::tan(argument->value());
}

Expression* Tan::derivative() {
	// d/dx tan(u) = (1 / cos^2(u)) * u'
	return new Divide(
		argument->derivative(),
		new Multiply(
			new Cos(argument->copy()),
			new Cos(argument->copy())
		)
	);
}

Tan* Tan::copy() {
	return new Tan(this);
}

std::string Tan::toString() {
	return "tan(" + argument->toString() + ")";
}