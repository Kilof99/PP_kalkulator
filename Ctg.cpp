#include "Ctg.h"
#include <cmath>
#include "Multiply.h"
#include "Divide.h"
#include "Sin.h"
#include "Constant.h"

Ctg::Ctg(Expression* arg) : Function(arg) {}
Ctg::Ctg(Ctg* origin) : Function(origin) {}

double Ctg::value() {
	return 1.0 / std::tan(argument->value());
}

Expression* Ctg::derivative() {
	// d/dx ctg(u) = -1 / sin^2(u) * u'
	return new Multiply(
		argument->derivative(), 
		new Divide(
			new Constant(-1), 
			new Multiply(new Sin(argument->copy()), new Sin(argument->copy()))
		)
	);
}

Ctg* Ctg::copy() {
	return new Ctg(this);
}

std::string Ctg::toString() {
	return "ctg(" + argument->toString() + ")";
}