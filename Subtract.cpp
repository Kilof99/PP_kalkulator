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

Subtract::Subtract(Expression* l, Expression* r) : Operation(l, r) {}
Subtract::Subtract(Subtract* origin) : Operation(origin) {}