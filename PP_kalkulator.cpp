#include <iostream>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Constant.h"
#include "Variable.h"

int main()
{
    Add test = Add(new Constant(14), new Variable());
    //Subtract test = Subtract(new Multiply(new Constant(4), new Multiply(new Variable(), new Variable())), new Constant(9)); //4x^2-9
    std::cout << test.toString() << ": " << test.value() << std::endl;
    std::cout << test.derivative()->toString() << ": " << test.derivative()->value() << std::endl;
}