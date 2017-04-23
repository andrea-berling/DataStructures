#ifndef LIST_CPP
#define LIST_CPP
#include "../include/List.h"

template<typename T>
List<T>::List()
{
	Next = this;
	Prev = this;
}
// Creates an empty list

template<typename T>
List<T>::~List()
{
    List<T>* tmp = this->next(this->head());

    while(!finished(tmp))
    { 
        free(this->prev(tmp));
        tmp = this->next(tmp);
    }

    //free(this->next(tmp));  // head
    
}
// Destructor

template<typename T>
bool List<T>::empty()
{
	return (Next == this) && (Prev == this);
}
// Returns true if the sequence is empty

template<typename T>
bool List<T>::finished(List<T>* p)
{
	return p == this;
}
// Returns true if the list is finished

template<typename T>
List<T>* List<T>::head()
{
	return Next;
}
// Returns the position of the first element

template<typename T>
List<T>* List<T>::tail()
{
	return Prev;
}
// Returns the position of the last element

template<typename T>
List<T>* List<T>::next(List<T>* p)
{
	return p->Next;
}
// Returns the position of p's next element

template<typename T>
List<T>* List<T>::prev(List<T>* p)
{
	return p->Prev;
}
// Returns the position of p's prev element

template<typename T>
List<T>* List<T>::insert(List<T>* p,T v)
{
	List<T>* t = new List<T>();
	t->value = v;
	t->Prev = p->Prev;
	t->Prev->Next = t;
	t->Next = p;
	p->Prev = t;
	return t;
}
// Inserts v in position p
// returns the position of the new inserted element 

template<typename T>
List<T>* List<T>::remove(List<T>* p)
{
	p->Prev->Next = p->Next;
	p->Next->Prev = p->Prev;
	List<T>* t = p->Next;
	free(p);
	return t;
}
// removes v in position p
// returns the position of p's next element

template<typename T>
T List<T>::read(List<T>* p)
{
	return p->value;
}
// returns the element in position p

template<typename T>
void List<T>::write(List<T>* p,T v)
{
	p->value = v;
}
// writes v in position p
#endif
