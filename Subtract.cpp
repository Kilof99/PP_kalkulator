/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Subtract.h"

double Subtract::value() {
	return left->value() - right->value();
}

Expression* Subtract::derivative() {
	return new Subtract(left->derivative(), right->derivative());
}

Subtract* Subtract::copy() {
	return new Subtract(this);
}

std::string Subtract::toString() {
	return "(" + left->toString() + "-" + right->toString() + ")";
}

Subtract::Subtract(Expression* l, Expression* r) : Operation(l, r) {}
Subtract::Subtract(Subtract* origin) : Operation(origin) {}