/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Constant.h"
#include <sstream>

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

std::string Constant::toString() {
	std::stringstream ss;
	ss << number;
	return ss.str();
}