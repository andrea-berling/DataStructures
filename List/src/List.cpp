#ifndef LIST_CPP
#define LIST_CPP
#include "../include/List.h"

template<typename T>
List<T>::List()
{
    first = new List<T>::Node(); 
    first->next = first;
    first->prev = first;
}
// Creates an empty list

template<typename T>
List<T>::List(const List& list):List()
{
    for(List<T>::iterator it = list.begin(); it != list.end(); ++it)
        insert(end(),*it);
}

template<typename T>
List<T>::~List()
{
    List<T>::iterator i = begin();

    while(i != end())
    {
        remove(i);
    }

    delete first;
}
template<typename T>
bool List<T>::empty() const
{
	return (first->next == first && first->prev == first);
}
// Returns true if the sequence is empty

/*
template<typename T>
bool List<T>::finished(const List_iterator<T> p) const
{
	return p.node == first;
}
*/
// Returns true if the list is finished

template<typename T>
bool List<T>::contains(const T v) const
{
    if(!empty())
    {
        for(List<T>::iterator it = begin(); it != end(); it++)
        {
            if((*it) == v)
                return true;
        }
        return false;
    }
    else
        return false;
}
// Returns true if the list contains v

template<typename T>
typename List<T>::iterator List<T>::begin() const
{
	return List<T>::iterator(first->next);
}
// Returns the position of the first element

template<typename T>
typename List<T>::iterator List<T>::end() const
{
	return List<T>::iterator(first);
}
// Returns the position of the last element

template<typename T>
void List<T>::insert(const List<T>::iterator p,const T v) const
{
    List<T>::Node* t = new List<T>::Node();
	t->value = v;
	t->prev = p.node->prev;
	t->prev->next = t;
	t->next = p.node;
	p.node->prev = t;
}
// Inserts v in position p
// returns the position of the new inserted element 

template<typename T>
void List<T>::insert(const T v) const
{
   insert(begin(),v); 
}
// Inserts v at the beginning

template<typename T>
void List<T>::remove(List<T>::iterator& p) const
{
    List<T>::Node* t;
	p.node->prev->next = p.node->next;
	p.node->next->prev = p.node->prev;
    t = p.node;
    p++;
	delete t;
}
// removes v in position p
// returns the position of p's next element

template<typename T>
void List<T>::write(const List<T>::iterator p,const T v) const
{
    if(p.node != nullptr && p.node != first) // can't check if the address is valid
        p.node->value = v;
}
// writes v in position p

/*
template<typename T>
List<T>::iterator(ListNode<T>* node):node(node)
{} 

template<typename T>
List<T>::iterator():node(nullptr)
{}

template<typename T>
List<T>::iterator(const List<T>::iterator& it)
{
    this->node = it.node;
}
// Copy constructor
// */

template<typename T>
T& List<T>::iterator::operator*() const
{
    return node->value;
}

template<typename T>
bool List<T>::iterator::operator==(const List<T>::iterator rhs) const
{
    return (this->node == rhs.node);
}

template<typename T>
bool List<T>::iterator::operator!=(const List<T>::iterator rhs) const
{
    return !(this->node == rhs.node);
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
    node = node->next;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    List<T>::iterator old = *this;
    ++(*this);
    return old;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator--()
{
    node = node->prev;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    List<T>::iterator old = *this;
    --(*this);
    return old;
}
#endif
