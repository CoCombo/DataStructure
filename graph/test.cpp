#include <iostream>
#include "graph.h"

int main()
{
    const char *vertex = "ABCD";
    int a0[] = {1,2,3};
    int a1[] = {0};
    int a2[] = {0};
    int a3[] = {0};
    std::vector<int> edge[4]= {std::vector<int>(a0, a0 + 3), 
			       std::vector<int>(a1, a1 + 1),
			       std::vector<int>(a2, a2 + 1),
			       std::vector<int>(a3, a3 + 1)};
   // std::cout << *a0 << " " << *(a0 + 3) << std::endl;
    Graph<char, 4> g(vertex, edge);
    //g.print();
    g.DFS();
    g.BFS();
    return 0;
}
