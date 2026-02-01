#include "Ctg.h"
#include <cmath>
#include "Multiply.h"
#include "Divide.h"
#include "Sin.h"
#include "Constant.h"

Ctg::Ctg(Expression* a) : Function(a) {}
Ctg::Ctg(Ctg* origin) : Function(origin) {}

double Ctg::value() {
	return 1.0 / std::tan(argument->value());
}

Expression* Ctg::derivative() {
	// d/dx ctg(u) = -1 / sin^2(u) * u'
	Expression* sinCopy1 = new Sin(argument->copy());
	Expression* sinCopy2 = new Sin(argument->copy());
	Expression* denom = new Multiply(sinCopy1, sinCopy2);
	Expression* minusOneOverSin2 = new Multiply(new Constant(-1), new Divide(new Constant(1), denom));
	return new Multiply(argument->derivative(), minusOneOverSin2);
}

Ctg* Ctg::copy() {
	return new Ctg(this);
}

std::string Ctg::toString() {
	return "ctg(" + argument->toString() + ")";
}