#include <iostream>
#include "Add.h"
#include "Constant.h"

int main()
{
    Add test = Add(new Constant(4), new Constant(7));
    std::cout << test.value() << std::endl;
    std::cout << test.derivative()->value() << std::endl;
}