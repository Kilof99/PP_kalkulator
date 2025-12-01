#include "Add.h"

double Add::value() {
	return left->value() + right->value();
}

Expression* Add::derivative() {
	return new Add(left->derivative(), right->derivative());
}

Add::Add(Expression *l, Expression *r) : Operation(l, r) {}