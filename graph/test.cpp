#include <iostream>
#include "graph.h"

int main()
{
    const char *vertex = "ABCD";
    int a0[] = {1,2,3};
    int a1[] = {0,2,3};
    int a2[] = {0,1,3};
    int a3[] = {0,1,2};
    std::vector<int> edge[4]= {std::vector<int>(a0, a0 + 3), 
			       std::vector<int>(a1, a1 + 3),
			       std::vector<int>(a2, a2 + 3),
			       std::vector<int>(a3, a3 + 3)};
   // std::cout << *a0 << " " << *(a0 + 3) << std::endl;
    Graph<char, 4> g(vertex, edge);
    g.print();
    return 0;
}
