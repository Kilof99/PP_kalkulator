/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Add.h"

double Add::value() {
	return left->value() + right->value();
}

Expression* Add::derivative() {
	return new Add(left->derivative(), right->derivative());
}

Add* Add::copy() {
	return new Add(this);
}

std::string Add::toString() {
	return "(" + left->toString() + "+" + right->toString() + ")";
}

Add::Add(Expression *l, Expression *r) : Operation(l, r) {}
Add::Add(Add* origin) : Operation(origin) {}