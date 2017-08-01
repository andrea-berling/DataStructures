#ifndef TREE_CPP
#define TREE_CPP
#include "../include/tree.h"
#include "../../Queue/include/queue.h"

template<typename T>
Tree<T>::Tree()
{
    root = new Tree<T>::Node();
}

template<typename T>
Tree<T>::Tree(const T v)
{
    root = new Tree<T>::Node(v);
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

/*
template<typename T>
Tree<T>::Tree(const Tree& t)
{
    T v = t.getRoot().getValue();
    this->root = new Tree<T>::Node(v);
    typename Tree<T>::Node* u
}
// Copy constructor
*/

template<typename T>
typename Tree<T>::Node* Tree<T>::getRoot() const
{
    return root;
}

/*
template<typename T>
typename Tree<T>::Node::Node() : parent(nullptr),child(nullptr),sibling(nullptr)
{ }

template<typename T>
typename Tree<T>::Node::TreeNode(const T value) : parent(nullptr),child(nullptr),sibling(nullptr),value(value)
{ }
*/

template<typename T>
T& Tree<T>::Node::getValue()
{
	return value;
}
// Retunrns the value of the current node

template<typename T>
void Tree<T>::Node::setValue(const T value)
{
    this->value = value;
}
// Retunrns the value of the current node

template<typename T>
typename Tree<T>::Node* Tree<T>::Node::getParent() const
{
	return parent;
}
// Returns the Parent; nullptr if absent

template<typename T>
typename Tree<T>::Node* Tree<T>::Node::getChild() const
{
	return child;
}
// Returns the leftmost Child

template<typename T>
typename Tree<T>::Node* Tree<T>::Node::getSibling() const
{
	return sibling;
}
// Returns the next Sibling

template<typename T>
void Tree<T>::Node::insertChild(Tree<T>::Node* t)
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
void Tree<T>::Node::insertSibling(Tree<T>::Node* t)
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
void Tree<T>::Node::deleteChild()
{
	Tree<T>::Node* newChild = child->getSibling();
	deleteTree(child);
	child = newChild;
}
// Deletes the subtree that is the leftmost Child of the current node

template<typename T>
void Tree<T>::Node::deleteSibling()
{
	Tree<T>::Node* newSibling = sibling->getSibling();
	deleteTree(sibling);
	sibling = newSibling;
}
// Deletes the subtree that is the next Sibling of the current node

template<typename T>
void Tree<T>::deleteTree(typename Tree<T>::Node* t)
{
	typename Tree<T>::Node* u = t->getChild();
	while (u != nullptr)
	{
		typename Tree<T>::Node* next = u->getSibling();
		deleteTree(u);
		u = next;
	}
	delete t;
}

#endif
