/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Multiply.h"
#include "Add.h"

double Multiply::value() {
	return left->value() * right->value();
}

Expression* Multiply::derivative() {
	return new Add(
		new Multiply(left->derivative(), right->copy()),
		new Multiply(left->copy(), right->derivative())
	);
}

Multiply* Multiply::copy() {
	return new Multiply(this);
}

std::string Multiply::toString() {
	return "(" + left->toString() + "*" + right->toString() + ")";
}

Multiply::Multiply(Expression* l, Expression* r) : Operation(l, r) {}
Multiply::Multiply(Multiply* origin) : Operation(origin) {}