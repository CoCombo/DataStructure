#include <iostream>
#include "DList.h"
#define BUFF 10

using std::cout;
using std::cin;
using std::endl;

int main()
{
    DList<int> list;
    int array[BUFF] = {1,3,2,4,7,5,6,9,0,8};

    for(const auto &i : array)
		list.push_back(i);
    list.print();
    return 0;
}
