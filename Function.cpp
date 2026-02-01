#include "Function.h"

Function::Function(Expression* arg) {
	argument = arg;
}

Function::Function(Function* origin) {
	argument = origin->argument;
}