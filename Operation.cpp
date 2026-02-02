/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Operation.h"

Operation::Operation(Expression *l, Expression *r) {
	left = l;
	right = r;
}

Operation::Operation(Operation* origin) {
	left = origin->left;
	right = origin->right;
}