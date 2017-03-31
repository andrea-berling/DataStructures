#ifndef LIST_CPP
#define LIST_CPP

List<T>::List()
{
	next = this;
	prev = this;
}
// Creates an empty list

List<T>::~List()
{
	List<T> *i = head();
	List<T> *tmp;
	while(!finished(tmp))
	{
		tmp = i;
		i = next(i);
		delete tmp;
	}
}
// Destructor

bool List<T>::empty()
{
	return (next == this) && (prev == this);
}
// Returns true if the sequence is empty

bool List<T>::finished(List* p)
{
	return p == this;
}
// Returns true if the list is finished
List<T>::List* head()
{
	return next;
}
// Returns the position of the first element
List* List<T>::tail()
{
	return prev;
}
// Returns the position of the last element
List* List<T>::next(List* p)
{
	return p->next;
}
// Returns the position of p's next element
List* List<T>::prev(List* p)
{
	return p->prev;
}
// Returns the position of p's prev element
List* List<T>::insert(List* p,T v)
{
	List<T>* t = new List<T>();
	t->value = v;
	t->prev = p->prev;
	t->prev->next = t;
	t->next = p;
	p->prev = t;
	return t;
}
// Inserts v in position p
// returns the position of the new inserted element 
List* List<T>::remove(List* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	List<T>* t = p->next;
	delete p;
	return t;
}
// removes v in position p
// returns the position of p's next element
T List<T>::read(List* p)
{
	return p->value;
}
// returns the element in position p
void List<T>::write(List* p,T v)
{
	p->value = v;
}
// writes v in position p
#endif
