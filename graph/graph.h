#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <queue>
#include <memory.h>

template <class T>
struct Edge
{
    int   vertexNum; 
    Edge *next;
};

template <class  T>
struct Vertex
{
    T     element;
    Edge *firstEdge;
};

template <class T, int SIZE>
class Graph
{
    public:
	Graph();
	Graph(const T *verArray, const std::vector<int> edgeArray[SIZE]);
       ~Graph();
        
	void print() const;
	void DFS  () const;
	void BFS  () const;

    private:
	void doDFS(int , vector<bool> &) const;
	Vertex<T> verTable[SIZE];
};

template <class T, int SIZE>
Graph<T, SIZE>::Graph()
{
    memset(verTable, 0, sizeof(verTable));
}

template <class T, int SIZE>
Graph<T, SIZE>::Graph(const T *verArray, const std::vector<int> edgeArray[SIZE])
{
    memset(verTable, 0, sizeof(verTable));
    for(int i = 0; i < SIZE; i++)
    {
	verTable[i].element = verArray[i];
	for(int j = 0; j < edgeArray[i].size(); j++)
	{
	    Edge *tmp             = new Edge;
	    tmp->vertexNum        = edgeArray[i][j];
	    tmp->next             = verTable[i].firstEdge;
	    verTable[i].firstEdge = tmp;
	}
    }
}

template <class T, int SIZE>
Graph<T, SIZE>::~Graph()
{
    for(int i = 0; i < SIZE; i++)
    {
	while(verTable[i].firstEdge)
	{
	    Edge *tmp = verTable[i].firstEdge;
	    verTable[i].firstEdge = tmp->next;
	    delet tmp;
	}
    }
}

template <class T, int SIZE>
void Graph<T, SIZE>::print() const
{
    for(int i = 0; i < SIZE; i++)
    {
	std::cout << verTable[i].element << " ";
	Edge *tmp = verTable.firstEdge;
	while(tmp)
	{
	    std::cout << verTable[tmp->vertexNum].element << " ";
	    tmp = tmp->next;
	}
	std::cout << std::endl;
    }
}

template <class T, int SIZE>
void Graph<T, SIZE>::DFS() const
{
    std::vector<bool> visit(SIZE, false);
    for(int i = 0; i < SIZE; i++)
    {
	if(!visit[i])
	    doDFS(i, visit);
    }
    std::cout << std::endl;
}

template <class T, int SIZE>
void Graph<T, SIZE>::doDFS(int i, vector<bool> &_visit) const
{
    _visit[i] = true;
    Vertex *tmp = verTable.firstEdge;
    while(tmp)
    {	
	if(!_visit[tmp->vertexNum])
	   doDFS(tmp->vertexNum, _visit);
	tmp = tmp->next;
    }
}
#endif
