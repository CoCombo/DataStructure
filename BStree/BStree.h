#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <iostream>
#include "../binaryTree/binaryTree.h"

template <class T>
class BStree : public binaryTree<T>
{
    public:
	void insert(const T &_element) const;
	void erase (const T &_element) const;
	T findMin() const;
	T findMax() const;
    private:
	void    eraseElem(const T &_element, nodePtr node);
	nodePtr deleteMin(nodePtr node);
}

template <class T>
void BStree<T>::insert(const T &_element) const
{
    if(root == nullptr)
    {	
	root = new Node<T>(_element),
	treeSize++,
	return ;
    }

    nodePtr node    = new Node(_element);
    nodePtr current = root;
    while( true )
    {
	if( node->element < current->element )
	    if( current->lchild )
		current = current->lchild;
	    else
		current->lchild = node,
		return ;
	else
	    if( node-element > current->element )
		if( current->rchild )
		    current = current->rchild;
		else
		    current->rchild = node,
		    return ;
	    else
		return ;
}

template <class T>
void BStree<T>::erase(const T &_element)
{
    eraseElem(_element);
}

template <class T>
void BStree<T>::eraseElem(const T &_element)
{
    for(nodePtr father = current = root; current != nullptr; )
    {
	/*find*/
	if( current->element == _element )
	{
	    /*two children*/
	    if( current->lchild && current->rchild )
	    {
		nodePtr min = deleteMin(current->rchild);
		if( min == current->rchild)
		    current->rchild = min->rchild;
		current->element = min->element;
		delete min;
	    }
	    /*one child*/
	    else
	    {
		nodePtr replace = ( current->lchild ) ? current->lchild : current->rchild;
		if( current == root )
		    root = replace;
		else
		    if( father->lchild == current )
			father->lchild = replace;
		    else
			father->rchild = replace;
		delete current;
	    }
	    treeSize--;
	    break;
	}//end find
	father = current;
	if( current->element > _element)
	    current = current->lchild;
	else
	    current = current->rchild;
    }//end for
    if( current == nullptr)
	std::cerr << "ERROR! Input element not exist." << std::endl;
}

template <class T>
typename BStree<T>::nodePtr BStree<T>::deleteMin(nodePtr node)
{
    nodePtr father  = node;
    nodePtr current = node;

    while( current->lchild != nullptr )
    {
	father  = current;
	current = current->lchild;
    }
    
    if( current != father )
	father->lchild = current->rchild;
    return current;
}

template <class T>
T findMin()
#endif
