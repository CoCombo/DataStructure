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
    T        element;
    Edge<T> *firstEdge;
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
	void doDFS(int , std::vector<bool> &) const;
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
	    Edge<T> *tmp             = new Edge<T>;
	    tmp->vertexNum           = edgeArray[i][j];
	    tmp->next                = verTable[i].firstEdge;
	    verTable[i].firstEdge    = tmp;
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
	    Edge<T> *tmp = verTable[i].firstEdge;
	    verTable[i].firstEdge = tmp->next;
	    delete tmp;
	}
    }
}

template <class T, int SIZE>
void Graph<T, SIZE>::print() const
{
    for(int i = 0; i < SIZE; i++)
    {
	std::cout << verTable[i].element << " ";
	Edge<T> *tmp = verTable[i].firstEdge;
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
void Graph<T, SIZE>::doDFS(int i, std::vector<bool> &_visit) const
{
    _visit[i] = true;
    Vertex<T> *tmp = verTable.firstEdge;
    while(tmp)
    {	
	if(!_visit[tmp->vertexNum])
	   doDFS(tmp->vertexNum, _visit);
	tmp = tmp->next;
    }
}

template <class T, int SIZE>
void Graph<T, SIZE>::BFS() const
{
    std::vector<bool> visit(SIZE, false);
    std::queue <int>  Queue;
   
    for(int i = 0; i < SIZE; i++)
    {
	if( !visit[i] )
	{
	    visit[i] = true;
	    std::cout << verTable[i].element << " ";
	    Queue.push(i);
	    while( !Queue.empty() )
	    {
		int tmpFront = Queue.front();
		Queue.pop();
		for(Edge<T> *tmp = verTable[i].firstEdge; tmp != nullptr; tmp = tmp->next)
		{
		    if( !visit[tmp->vertexNum] )
		    {
			std::cout << verTable[tmp->vertexNum].dara;
			visit[tmp->vertexNum] = true;
			Queue.push(tmp->vertexNum);
		    }
		}
	    }
	}
    }
}
#endif
