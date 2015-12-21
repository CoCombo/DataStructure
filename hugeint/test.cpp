#include <iostream>
#include "hugeint.h"

int main()
{
    INT hugeNum1("12345");
    INT hugeNum2("123");
    hugeNum1 += hugeNum2;
    hugeNum1.print();
    ++hugeNum1;
    hugeNum1.print();
    return 0;
}
