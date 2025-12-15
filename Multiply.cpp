#include "Multiply.h"
#include "Add.h"

double Multiply::value() {
	return left->value() * right->value();
}
/*
Expression* Multiply::derivative() {
	return new Add(new Multiply(left->derivative(), new Expression(right)), new Multiply());
}*/

Multiply::Multiply(Expression* l, Expression* r) : Operation(l, r) {}
Multiply::Multiply(Multiply* origin) : Operation(origin) {}