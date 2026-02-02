#include <iostream>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Constant.h"
#include "Variable.h"
#include "Parser.h"

using namespace std;

int main()
{
    //Add test = Add(new Constant(14), new Variable());
    //Subtract test = Subtract(new Multiply(new Constant(4), new Multiply(new Variable(), new Variable())), new Constant(9)); //4x^2-9
    //std::cout << test.toString() << ": " << test.value() << std::endl;
    //std::cout << test.derivative()->toString() << ": " << test.derivative()->value() << std::endl;

	cout << "Podaj wyrazenie do obliczenia:" << endl;
    string input;
    getline(std::cin, input);

    Expression* expr = Parser::parseString(input);
    cout << "Wyrazenie: " << expr->toString() << endl;
	cout << "Pochodna: " << expr->derivative()->toString() << endl;
	cout << endl << "Podaj wartosc zmiennej x:" << endl;

	double x_value;
	cin >> x_value;
	Variable::x = x_value;

	cout << "Wartosc wyrazenia dla x=" << x_value << ": " << expr->value() << endl;
	cout << "Wartosc pochodnej dla x=" << x_value << ": " << expr->derivative()->value() << endl;


    delete expr;
	system("pause");
    return 0;
}