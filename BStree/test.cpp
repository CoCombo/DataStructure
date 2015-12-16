#include <iostream>
#include "BStree.h"

int main()
{
    BStree<int> bstree;
    int data[10] = {2,5,9,1,4,0,2,3,7,8};
    for(int i = 0; i < 10; i++)
	bstree.insert(data[i]);
    bstree.erase(11);
    bstree.print_tree(std::cout);
    std::cout << std::endl;
    bstree.erase(4);
    bstree.print_tree(std::cout);
    std::cout << bstree.findMin() << " " 
	      << bstree.findMax() << std::endl;
    return 0;
}
