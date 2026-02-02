#include "Variable.h"
#include "Constant.h"

double Variable::x = 1;

double Variable::value() {
	return this->x;
}

Expression* Variable::derivative() {
	return new Constant(1);
}

Variable::Variable() {}

Variable* Variable::copy() {
	return new Variable();
}

std::string Variable::toString() {
	return "x";
}