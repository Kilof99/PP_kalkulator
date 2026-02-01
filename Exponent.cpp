#include "Exponent.h"
#include "Multiply.h"
#include "Constant.h"
#include <cmath>

// left = podstawa
// right = wyk³adnik
// assumes Expression^Constant

double Exponent::value() {
	return std::pow(left->value(), right->value());
}

Expression* Exponent::derivative() {
	double n = right->value();
	if (n == 0) {
		return new Constant(0);
	}

	if (n == 1) {
		// u^1 == u => d/dx u = u'
		return left->derivative();
	}

	// d/dx (u^n) = n * u^(n-1) * u'
	return new Multiply(
		new Multiply(
			new Constant(n),
			new Exponent(left->copy(), new Constant(n - 1))
		),
		left->derivative()
	);
}

Exponent* Exponent::copy() {
	return new Exponent(this);
}

std::string Exponent::toString() {
	return left->toString() + "^" + right->toString();
}

Exponent::Exponent(Expression* l, Expression* r) : Operation(l, r) {}
Exponent::Exponent(Exponent* origin) : Operation(origin) {}