#include "Exponent.h"
#include "Multiply.h"
#include "Constant.h"
#include "Add.h"
#include "Divide.h"
#include "Ln.h"
#include <cmath>

// left = podstawa
// right = wyk³adnik

double Exponent::value() {
	return std::pow(left->value(), right->value());
}

Expression* Exponent::derivative() {
	// w przypadku sta³ego wykladnika n: d/dx (u^n) = n * u^(n-1) * u'
	Constant* constantExponent = dynamic_cast<Constant*>(right);
	if (constantExponent) {
		double n = constantExponent->number;

		if (n == 0) {
			return new Constant(0);
		}
		if (n == 1) {
			// d/dx (u^1) = u'
			return left->derivative();
		}

		// ogólny przypadek dla sta³ego n: d/dx (u^n) = n * u^(n-1) * u'
		return new Multiply(
			new Multiply(
				new Constant(n),
				new Exponent(left->copy(), new Constant(n - 1))
			),
			left->derivative()
		);
	}

	// forma ogolna gdy wykladnik jest wyrazeniem: d/dx (u^v) = u^v * (v' * ln(u) + v * (u'/u))
	return new Multiply(
		new Exponent(left->copy(), right->copy()),
		new Add(
			new Multiply(
				right->derivative(),
				new Ln(left->copy())
			),
			new Multiply(
				right->copy(),
				new Divide(
					left->derivative(),
					left->copy()
				)
			)
		)
	);
}

Exponent* Exponent::copy() {
	return new Exponent(this);
}

std::string Exponent::toString() {
	return "(" + left->toString() + "^" + right->toString() + ")";
}

Exponent::Exponent(Expression* l, Expression* r) : Operation(l, r) {}
Exponent::Exponent(Exponent* origin) : Operation(origin) {}