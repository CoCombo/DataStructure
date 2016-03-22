#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> queue;
    std::cout << "queue size: "    << queue.size() << std::endl;

    for(int i = 0; i < 10; i++)
	queue.back(i);
    std::cout << "queue size: " << queue.size() << std::endl;
    for(int i = 0; i < 5; i++)
	queue.front();
    std::cout << "queue size: " << queue.size() << std::endl;

}
