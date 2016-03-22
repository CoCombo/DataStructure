#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <iostream>
#include "../binaryTree/binaryTree.h"

template <class T>
class BStree : public binaryTree<T>
{
    public:
        typedef Node<T>* nodePtr;
	void insert(const T &_element);
	void erase (const T &_element);
	T findMin() const;
	T findMax() const;
    private:
	void    eraseElem(const T &_element);
	nodePtr deleteMin(nodePtr node);
};

template <class T>
void BStree<T>::insert(const T &_element)
{
    if(binaryTree<T>::root == nullptr)
    {	
	binaryTree<T>::root = new Node<T>(_element);
	binaryTree<T>::treeSize++;
	return ;
    }

    auto node    = new Node<T>(_element);
    auto current = binaryTree<T>::root;
    while( true )
    {
	if( node->element < current->element )
	    if( current->lchild )
		current = current->lchild;
	    else
		{
		    current->lchild = node;
		    return ;
		}
	else
	    if( node->element > current->element )
		if( current->rchild )
		    current = current->rchild;
		else
		{
		    current->rchild = node;
		    return ;
		}
	    else
		return ;
    }
}

template <class T>
void BStree<T>::erase(const T &_element)
{
    eraseElem(_element);
}

template <class T>
void BStree<T>::eraseElem(const T &_element)
{
    auto father  = binaryTree<T>::root;
    auto current = binaryTree<T>::root;
    for( ; current != nullptr; )
    {
	/*find*/
	if( current->element == _element )
	{
	    /*two children*/
	    if( current->lchild && current->rchild )
	    {
		auto min = deleteMin(current->rchild);
		if( min == current->rchild)
		    current->rchild = min->rchild;
		current->element = min->element;
		delete min;
	    }
	    /*one child*/
	    else
	    {
		auto replace = ( current->lchild ) ? current->lchild : current->rchild;
		if( current == binaryTree<T>::root )
		    binaryTree<T>::root = replace;
		else
		    if( father->lchild == current )
			father->lchild = replace;
		    else
			father->rchild = replace;
		delete current;
	    }
	    binaryTree<T>::treeSize--;
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
    auto father  = node;
    auto current = node;

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
T BStree<T>::findMin() const
{
    auto current = binaryTree<T>::root;
    for( ; current->lchild; )
	current = current->lchild;
    
    return current->element;
}

template <class T>
T BStree<T>::findMax() const
{
    auto current = binaryTree<T>::root;
    for( ; current->rchild; )
	current = current->rchild;

    return current->element;
}
#endif
