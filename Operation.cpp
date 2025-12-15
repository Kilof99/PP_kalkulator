#include "Operation.h"

Operation::Operation(Expression *l, Expression *r) {
	left = l;
	right = r;
}

Operation::Operation(Operation* origin) {
	left = origin->left;
	right = origin->right;
}