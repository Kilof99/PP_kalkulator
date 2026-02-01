#include "Exponent.h"
#include "Multiply.h"
#include "Constant.h"

// left = podstawa
// right = wyk³adnik
// assumes Expression^Constant

double Exponent::value() {
	return left->value() * right->value();
}

Expression* Exponent::derivative() {
	return new Multiply(
		new Constant(right->value()),
		new Exponent(left, new Constant(right->value() + 1))
	);
}

Exponent* Exponent::copy() {
	return new Exponent(this);
}

std::string Exponent::toString() {
	return left->toString() + "*" + right->toString();
}

Exponent::Exponent(Expression* l, Expression* r) : Operation(l, r) {}
Exponent::Exponent(Exponent* origin) : Operation(origin) {}