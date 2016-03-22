#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#define MAXSIZE 100

template <class T>
struct Node
{
    T element;
    Node *next;
    Node *prev;

    explicit Node(const T &_element) : element(_element), next(nullptr), prev(nullptr) {}
};

template <class T>
class Queue
{
    public:
	typedef Node<T>* nodePtr;

	Queue() : queueSize(0)
	{
	    head = new Node<T>(0);
	    tail = new Node<T>(0);

	    head->next = tail;
	    tail->prev = head;
	}
       ~Queue() { clean(); }

        void front();
	void back ( const T &_element);
	
	inline int  size ();
	inline bool empty();

	void clean();
	
    private:
	nodePtr head;
	nodePtr tail;
	int     queueSize;
};

template <class T>
void Queue<T>::front()
{
    if(queueSize == 0)
    {
	std::cout << "Queue empty!" << std::endl;
	return ;
    }

    auto node = head->next;
    
    head->next       = node->next;
    node->next->prev = head;
    delete node;
    queueSize--;
}

template <class T>
void Queue<T>::back(const T &_element)
{
    if(queueSize == MAXSIZE)
    {
	std::cout << "Queue full!" << std::endl;
	return ;
    }
    auto node = new Node<T>(_element);

    node->prev       = tail->prev;
    node->next       = tail;
    tail->prev->next = node;
    tail->prev       = node;
    queueSize++;
}

template <class T>
inline int Queue<T>::size()
{
    return queueSize;
}

template <class T>
inline bool Queue<T>::empty()
{
    return queueSize == 0;
}

template <class T>
void Queue<T>::clean()
{
    for(auto node = head->next; node != tail; node = node->next)
    {
	auto current = node;
	delete current;
    }
    delete head;
    delete tail;
}
#endif
