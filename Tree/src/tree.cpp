#ifndef TREE_CPP
#define TREE_CPP
#include "../include/tree.h"

template<typename T>
Tree<T>::Tree(T v)
{
	value = v;
	Parent = nullptr;	
	Child = nullptr;	
	Sibling = nullptr;	
}
// Constructs a tree with a single node containing v

template<typename T>
T Tree<T>::read()
{
	return value;
}
// Retunrns the value of the current node

template<typename T>
Tree<T>* Tree<T>::parent()
{
	return Parent;
}
// Returns the Parent; nullptr if absent

template<typename T>
Tree<T>* Tree<T>::leftmostChild()
{
	return Child;
}
// Returns the leftmost Child

template<typename T>
Tree<T>* Tree<T>::rightSibling()
{
	return Sibling;
}
// Returns the next Sibling

template<typename T>
void Tree<T>::insertChild(Tree<T>* t)
{
	if (t->Parent == nullptr)
	{
		t->Sibling = Child;
		t->Parent = this;
		Child = t;
	}
}
// Inserts t subtree as the leftmost Child of the current node
// Precondition: t->Parent == nullptr 

template<typename T>
void Tree<T>::insertSibling(Tree<T>* t)
{
	if (t->Parent == nullptr)
	{
		t->Parent = Parent;
		t->Sibling = Sibling;
		Sibling = t;
	}
}
// Inserts t subtree as the next Sibling of the current node
// Precondition: t->Parent == nullptr 

template<typename T>
void Tree<T>::deleteChild()
{
	Tree<T>* newChild = Child->rightSibling();
	deleteTree(Child);
	Child = newChild;
}
// Deletes the subtree that is the leftmost Child of the current node

template<typename T>
void Tree<T>::deleteSibling()
{
	Tree<T>* newSibling = Sibling->rightSibling();
	deleteTree(Sibling);
	Sibling = newSibling;
}
// Deletes the subtree that is the next Sibling of the current node

template<typename T>
void deleteTree(Tree<T>* t)
{
	Tree<T>* u = t->leftmostChild();
	while (u != nullptr)
	{
		Tree<T>* next = u->rightSibling();
		deleteTree(u);
		u = next;
	}
	delete t;
}

#endif
