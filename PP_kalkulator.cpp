#include <iostream>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Constant.h"
#include "Variable.h"

int main()
{
    Multiply test = Multiply(new Constant(14), new Variable());
    std::cout << test.value() << std::endl;
    std::cout << test.derivative()->value() << std::endl;
}