#include "Ln.h"
#include <cmath>
#include "Multiply.h"
#include "Divide.h"
#include "Constant.h"

Ln::Ln(Expression* arg) : Function(arg) {}
Ln::Ln(Ln* origin) : Function(origin) {}

double Ln::value() {
	return std::log(argument->value());
}

Expression* Ln::derivative() {
	// d/dx ln(u) = (1 / u) * u' = u' / u
	return new Divide(argument->derivative(), argument->copy());
}

Ln* Ln::copy() {
	return new Ln(this);
}

std::string Ln::toString() {
	return "ln(" + argument->toString() + ")";
}