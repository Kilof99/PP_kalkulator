#include <iostream>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Constant.h"
#include "Variable.h"

int main()
{
    Divide test = Divide(new Constant(14), new Variable());
    std::cout << test.toString() << ": " << test.value() << std::endl;
    std::cout << test.derivative()->toString() << ": " << test.derivative()->value() << std::endl;
}