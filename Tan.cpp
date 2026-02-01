#include "Tan.h"
#include <cmath>
#include "Multiply.h"
#include "Divide.h"
#include "Multiply.h"
#include "Cos.h"
#include "Constant.h"

Tan::Tan(Expression* a) : Function(a) {}
Tan::Tan(Tan* origin) : Function(origin) {}

double Tan::value() {
	return std::tan(argument->value());
}

Expression* Tan::derivative() {
	// d/dx tan(u) = (1 / cos^2(u)) * u'
	Expression* cosCopy1 = new Cos(argument->copy());
	Expression* cosCopy2 = new Cos(argument->copy());
	Expression* denom = new Multiply(cosCopy1, cosCopy2);
	Expression* sec2 = new Divide(new Constant(1), denom);
	return new Multiply(argument->derivative(), sec2);
}

Tan* Tan::copy() {
	return new Tan(this);
}

std::string Tan::toString() {
	return "tan(" + argument->toString() + ")";
}