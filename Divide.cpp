#include "Divide.h"
#include "Subtract.h"
#include "Multiply.h"

double Divide::value() {
	return left->value() / right->value();
}

Expression* Divide::derivative() {
	return new Divide(
		new Subtract(
			new Multiply(left->derivative(), right->copy()),
			new Multiply(left->copy(), right->derivative())),
		new Multiply(right->copy(), right->copy())
	);
}

Divide* Divide::copy() {
	return new Divide(this);
}

std::string Divide::toString() {
	return left->toString() + "/" + right->toString();
}

Divide::Divide(Expression* l, Expression* r) : Operation(l, r) {}
Divide::Divide(Divide* origin) : Operation(origin) {}