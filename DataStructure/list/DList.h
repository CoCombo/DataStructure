#ifndef _DLIST_H_
#define _DLIST_H_

#include <iostream>
#include <stdexcept>
template <typename T>
class DList
{
    struct Node
    {
	T element;
	Node *next;
	Node *prev;

	explicit Node(const T &_element) : element(_element),  next(nullptr), prev(nullptr) {}
	explicit Node()                  : element(),          next(nullptr), prev(nullptr) {}
	~Node() { next = prev = nullptr; }
    };
    
    private:
	Node *head;
	Node *tail;
	int   listSize;
    public:
	DList();
	~DList();

	bool empty() const { return listSize == 0 ? true : false; }
	int  size()  const { return listSize; }

	void push_back (const T &_element);
	void push_front(const T &_element);
	T    pop_back  ();
	T    pop_front ();

	void insert_after(const T &_element, int pos);
	void erase(int pos);
	void erase(int beg, int end);
	void print();
	void clear();

};

template <typename T>
DList<T>::DList()
{
    listSize = 0;
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;
}

template <typename T>
DList<T>::~DList()
{
    clear();
}

template <typename T>
void DList<T>::push_back(const T &_element)
{
    Node *tmp = new Node(_element);

    tmp->prev        = tail->prev; 
    tmp->next        = tail;
    tail->prev->next = tmp;
    tail->prev       = tmp;

    listSize++;
}

template <typename T>
void DList<T>::push_front(const T &_element)
{
    Node *tmp = new Node(_element);

    tmp->prev        = head;
    tmp->next        = head->next;
    head->next->prev = tail;
    head->next       = tail;

    listSize++;
}

template <typename T>
T DList<T>::pop_back()
{
   /* if( listSize == 0)
{	//std::runtime_error err;
	throw runtime_error("List empty!");}*/

    T tmp         = tail->prev->element;
    auto tmpNode  = tail->prev;

    tmpNode->prev->next = tail;
    tail->prev          = tmpNode->prev;

    delete tmpNode;
    listSize--;

    return tmp;
}

template <typename T>
T DList<T>::pop_front()
{
   /* if(listSize == 0)
	{//std::runtime_error err;
	throw runtime_error("List");}*/

    T tmp         = head->next->element;
    auto tmpNode  = head->next;

    head->next          = tmpNode->next;
    tmpNode->next->prev = head;

    delete tmpNode;
    listSize--;

    return tmp;
}

template <typename T>
void DList<T>::clear()
{
    for(auto current = head->next; listSize != 0; listSize--)
    {
	auto nextNode = current->next;

	delete current;

	current = nextNode;
    }
   delete head;
   delete tail;
}

template <typename T>
void DList<T>::print()
{
   /* if(listSize == 0)
{	//std::runtime_error err;
	throw runtime_error("List");}*/
    for(auto current = head->next; current != tail; current = current->next)
	std::cout << current->element << std::endl;
}
#endif

