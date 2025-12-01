#include "Variable.h"
#include "Constant.h"

double Variable::value() {
	return 1;
}

Expression* Variable::derivative() {
	return new Constant(1);
}