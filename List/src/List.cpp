#ifndef LIST_CPP
#define LIST_CPP
#include "../include/List.h"

template<typename T>
List<T>::List()
{
    first = new ListNode<T>(); 
    first->next = first;
    first->prev = first;
}
// Creates an empty list

template<typename T>
List<T>::~List()
{
    List_iterator<T> tmp;
    List_iterator<T> i = first->next;
    while(!finished(i))
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

template<typename T>
bool List<T>::finished(const List_iterator<T> p) const
{
	return p.node == first;
}
// Returns true if the list is finished

template<typename T>
bool List<T>::contains(const T v) const
{
    if(!empty())
    {
        for(iterator it = begin(); it != end(); it++)
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
List_iterator<T> List<T>::begin() const
{
	return List_iterator<T>(first->next);
}
// Returns the position of the first element

template<typename T>
List_iterator<T> List<T>::end() const
{
	return List_iterator<T>(first);
}
// Returns the position of the last element

template<typename T>
void List<T>::insert(const List_iterator<T> p,const T v) const
{
	ListNode<T>* t = new ListNode<T>();
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
void List<T>::remove(List_iterator<T>& p) const
{
    ListNode<T>* t;
	p.node->prev->next = p.node->next;
	p.node->next->prev = p.node->prev;
    t = p.node;
    p++;
	delete t;
}
// removes v in position p
// returns the position of p's next element

template<typename T>
void List<T>::write(const List_iterator<T> p,const T v) const
{
    if(p.node != first)
        p.node->value = v;
}
// writes v in position p

template<typename T>
List_iterator<T>::List_iterator(ListNode<T>* node)
{ 
    this->node = node;
}

template<typename T>
List_iterator<T>::List_iterator():node(nullptr)
{ }

template<typename T>
T& List_iterator<T>::operator*() const
{
    return node->value;
}

template<typename T>
bool List_iterator<T>::operator==(const List_iterator<T> rhs) const
{
    return (this->node == rhs.node);
}

template<typename T>
bool List_iterator<T>::operator!=(const List_iterator<T> rhs) const
{
    return !(this->node == rhs.node);
}

template<typename T>
List_iterator<T>& List_iterator<T>::operator++()
{
    node = node->next;
    return *this;
}

template<typename T>
List_iterator<T> List_iterator<T>::operator++(int)
{
    List_iterator<T> old = *this;
    ++(*this);
    return old;
}

template<typename T>
List_iterator<T>& List_iterator<T>::operator--()
{
    node = node->prev;
    return *this;
}

template<typename T>
List_iterator<T> List_iterator<T>::operator--(int)
{
    List_iterator<T> old = *this;
    --(*this);
    return old;
}
#endif
