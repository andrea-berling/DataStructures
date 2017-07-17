#ifndef TREE_CPP
#define TREE_CPP
#include "../include/tree.h"
#include "../../Queue/include/queue.h"

template<typename T>
Tree<T>::Tree()
{
    root = new TreeNode<T>();
}

template<typename T>
Tree<T>::Tree(T v)
{
    root = new TreeNode<T>(v);
}
// Constructs a tree with a single node containing v

template<typename T>
Tree<T>::~Tree()
{
    if(root != nullptr)
    {
        deleteTree(root);
    }
}
// Constructs a tree with a single node containing v

template<typename T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}

template<typename T>
TreeNode<T>::TreeNode() : parent(nullptr),child(nullptr),sibling(nullptr)
{ }

template<typename T>
TreeNode<T>::TreeNode(T value) : parent(nullptr),child(nullptr),sibling(nullptr),value(value)
{ }

template<typename T>
T TreeNode<T>::getValue()
{
	return value;
}
// Retunrns the value of the current node

template<typename T>
void TreeNode<T>::setValue(T value)
{
    this->value = value;
}
// Retunrns the value of the current node

template<typename T>
TreeNode<T>* TreeNode<T>::getParent()
{
	return parent;
}
// Returns the Parent; nullptr if absent

template<typename T>
TreeNode<T>* TreeNode<T>::getChild()
{
	return child;
}
// Returns the leftmost Child

template<typename T>
TreeNode<T>* TreeNode<T>::getSibling()
{
	return sibling;
}
// Returns the next Sibling

template<typename T>
void TreeNode<T>::insertChild(TreeNode<T>* t)
{
	if (t->parent == nullptr)
	{
		t->sibling = child;
		t->parent = this;
		child = t;
	}
}
// Inserts t subtree as the leftmost Child of the current node
// Precondition: t->Parent == nullptr 

template<typename T>
void TreeNode<T>::insertSibling(TreeNode<T>* t)
{
	if (t->parent == nullptr)
	{
		t->parent = parent;
		t->sibling = sibling;
		sibling = t;
	}
}
// Inserts t subtree as the next Sibling of the current node
// Precondition: t->Parent == nullptr 

template<typename T>
void TreeNode<T>::deleteChild()
{
	TreeNode<T>* newChild = child->getSibling();
	deleteTree(child);
	child = newChild;
}
// Deletes the subtree that is the leftmost Child of the current node

template<typename T>
void TreeNode<T>::deleteSibling()
{
	TreeNode<T>* newSibling = sibling->getSibling();
	deleteTree(sibling);
	sibling = newSibling;
}
// Deletes the subtree that is the next Sibling of the current node

template<typename T>
void deleteTree(TreeNode<T>* t)
{
	TreeNode<T>* u = t->getChild();
	while (u != nullptr)
	{
		TreeNode<T>* next = u->getSibling();
		deleteTree(u);
		u = next;
	}
	delete t;
}

#endif
