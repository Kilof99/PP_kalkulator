#include "Constant.h"

Constant::Constant(double value) {
	number = value;
}

Expression* Constant::derivative() {
	return new Constant(0);
}

double Constant::value() {
	return number;
}

Constant* Constant::copy() {
	return new Constant(this->number);
}