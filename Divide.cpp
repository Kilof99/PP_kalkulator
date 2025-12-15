#include "Divide.h"

double Divide::value() {
	return left->value() / right->value();
}
/*
Expression* Divide::derivative() {
	return new Divide(left->derivative(), right->derivative());
}*/

Divide::Divide(Expression* l, Expression* r) : Operation(l, r) {}
Divide::Divide(Divide* origin) : Operation(origin) {}