#include <iostream>
#include "hugeint.h"

int main()
{
    INT hugeNum1("-123");
    INT hugeNum2("-9980");
    hugeNum1 += hugeNum2;
    hugeNum1.print();
   // ++hugeNum1;
   // hugeNum1.print();
    return 0;
}
