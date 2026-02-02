/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Function.h"

Function::Function(Expression* arg) {
	argument = arg;
}

Function::Function(Function* origin) {
	argument = origin->argument;
}