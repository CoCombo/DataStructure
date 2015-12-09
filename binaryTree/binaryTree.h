#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#define MAX(a, b) (a > b ? a : b)

template <class T>
class binaryTree
{
    protected:
	struct Node
	{
	    T element;
	    Node *lchild;
	    Node *rchild;
    
            explicit Node() : element(), lchild(nullptr), rchild(nullptr) {}
	};

    protected:
	int   treeSize;
	Node *root;

    public:
	explicit binaryTree() : treeSize(0), root(nullptr) {}
	virtual ~binaryTree() {clear();}

	void clear(Node *node);

	int  depth(const Node *node)                            const;
	int  size()                                             const;
	void print_tree(std::ostream &output, const Node *node) const;

	virtual void insert(const T &_element)    const = 0;
	virtual void erase (const T &_element)          = 0;
	//virtual void print (std::ostream &output) const = 0;
};

template <class T>
int binaryTree<T>::depth(const Node *node) const
{
    if( node == nullptr)
	return 0;
    else
	return 1 + MAX( depth(node->lchild), depth(node->rchild) );
}

template <class T>
int binaryTree<T>::size() const
{
    return treeSize;
}

template <class T>
void print_tree(std::ostream &output, const Node *node) const
{
    if(node == nullptr)
	return ;
    output << node->element;
    print_tree(node->lchild);
    print_tree(node->rchild);
}

template <class T>
void clean(Node *node)
{
    if(node == nullptr)
	return ;
    clean(node->lchild);
    clean(node->rchild);
    delete node;
}
