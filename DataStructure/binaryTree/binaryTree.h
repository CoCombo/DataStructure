#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#define MAX(a, b) (a > b ? a : b)

template <class T>
struct Node
{
    T	element;
    Node *lchild;
    Node *rchild;

    explicit Node(const T &_element) : element(_element), lchild(nullptr), rchild(nullptr) {}
};

template <class T>
class binaryTree
{
    public:
	typedef Node<T>* nodePtr;
    protected:
	int     treeSize;
	nodePtr root;

    public:
	explicit binaryTree() : treeSize(0), root(nullptr) {}
	virtual ~binaryTree()                              {clean(root);}

	void clean(nodePtr node);

	int  depth(const nodePtr node)                            const;
	int  size()                                               const;
	void print_tree(std::ostream &output)                     const;

	virtual void insert(const T &_element)          = 0;
	virtual void erase (const T &_element)          = 0;
	//virtual void print (std::ostream &output) const = 0;
    private:
	void print(std::ostream &output, nodePtr node) const;
};

template <class T>
int binaryTree<T>::depth(const nodePtr node) const
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
void binaryTree<T>::print_tree(std::ostream &output) const
{
    print(output, root);
}

template <class T>
void binaryTree<T>::clean(nodePtr node)
{
    if(node == nullptr)
	return ;
    clean(node->lchild);
    clean(node->rchild);
    delete node;
}

template <class T>
void binaryTree<T>::print(std::ostream &output, nodePtr node) const
{
    if(node == nullptr)
	return ;
    output << node->element;
    print(output, node->lchild);
    print(output, node->rchild);
}
#endif
