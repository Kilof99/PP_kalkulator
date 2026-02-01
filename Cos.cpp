#include "Cos.h"
#include <cmath>
#include "Multiply.h"
#include "Sin.h"
#include "Constant.h"

Cos::Cos(Expression* a) : Function(a) {}
Cos::Cos(Cos* origin) : Function(origin) {}

double Cos::value() {
	return std::cos(argument->value());
}

Expression* Cos::derivative() {
	// d/dx cos(u) = -sin(u) * u'
	// return u' * (-sin(u))
	return new Multiply(argument->derivative(),
		new Multiply(new Constant(-1), new Sin(argument->copy()))
	);
}

Cos* Cos::copy() {
	return new Cos(this);
}

std::string Cos::toString() {
	return "cos(" + argument->toString() + ")";
}