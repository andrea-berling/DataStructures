#ifndef SET_CPP
#define SET_CPP
#include "../include/set.h"

template<typename T>
Set<T>::Set()
{
    elements = new List<T>();
    cardinality = 0;
}
// Default constructor; creates a new empty set

template<typename T>
bool Set<T>::isEmpty()
{
    return cardinality == 0;
}
// Returns true if the set is empty, false otherwise

template<typename T>
bool Set<T>::contains(T x)
{
    if(!this->isEmpty())
    {
        for(List<T>* i = elements->head(); !elements->finished(i); i = elements->next(i))
        {
            if(elements->read(i) == x)
                return true;
        }

        return false;

    }
    else
        return false;
}
// Returns true if the set contains x, false otherwise

template<typename T>
T* Set<T>::lookup(T x)
{
    T* e = nullptr;
    bool found = false;

    if(!this->isEmpty())
    {
        List<T>* i = elements->head();
        while(!elements->finished(i) && !found)
        {
            if(elements->read(i) == x)
            {
                *e = x;
                found = true;
            }
            i = elements->next(i);
        }
    }

    return e;
}
// Return a pointer to the element x if present, nil otherwise

template<typename T>
bool Set<T>::insert(T x)
{
    if(!this->contains(x))
    {
        elements->insert(elements->head(), x);
        cardinality++;

        return true;
    }
    else
        return false;
}
// Returns true if x is not in the element and is successfully inserted; false if present

template<typename T>
bool Set<T>::remove(T x)
{
    bool done = false;

    for(List<T>* it = elements->head(); (it != elements->next(elements->tail())) && !done; it = elements->next(it))
    {
        if (elements->read(it) == x)
        {
            elements->remove(it);
            done = true;
        }
    }

    if(done)
        return true;
    else
        return false;
}
// Return ture if x is present in the set and removes it; false if absent

// ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

template<typename T>
set_iterator<T> Set<T>::begin()
{
    set_iterator<T> it;

    return it.begin(elements);
}
// Returns a reference to the first element in the list

template<typename T>
set_iterator<T> Set<T>::end()
{
    set_iterator<T> it;

    return it.end(elements);
}
// Returns a reference to the end fo the list

template<typename T>
set_iterator<T>::set_iterator()
{
    baseList = nullptr;
    p = nullptr;
}

template<typename T>
set_iterator<T>::set_iterator(const set_iterator& it)
{
    baseList = it.baseList;
    p = it.p;
}

template<typename T>
set_iterator<T> set_iterator<T>::begin(List<T>* l)
{
    baseList = l;
    p = l->head();
    
    return *this;
}

template<typename T>
set_iterator<T> set_iterator<T>::end(List<T>* l)
{
    if(baseList != l)
        baseList = l;

    p = l->next(l->tail());

    return *this;
}

template<typename T>
void set_iterator<T>::operator =(const set_iterator<T>& rightside)
{
    baseList = rightside.baseList;
    p = rightside.p;
}

template<typename T>
set_iterator<T> set_iterator<T>::operator ++() //prefix
{
    p = baseList->next(p);

    return p;
}

template<typename T>
set_iterator<T> set_iterator<T>::operator ++( int ) //postfix
{
    set_iterator<T> oldit(*this);

    p = baseList->next(p);

    return oldit;
}

template<typename T>
set_iterator<T> set_iterator<T>::operator --() //prefix
{
    p = baseList->next(p);

    return p;
}

template<typename T>
set_iterator<T> set_iterator<T>::operator --( int ) //postfix
{
    set_iterator<T> oldit(*this);

    p = baseList->prev(p);

    return oldit;
}

template<typename T>
T set_iterator<T>::operator *()
{
    if(!baseList->finished(p))
        return baseList->read(p);
}

template<typename T>
bool operator ==(const set_iterator<T>& it1, const set_iterator<T>& it2)
{
    return (it1.baseList == it2.baseList) && (it1.p == it2.p);
}

template<typename T>
bool operator !=(const set_iterator<T>& it1, const set_iterator<T>& it2)
{
    return !(it1 == it2);
}

template<typename T>
int size()
{
    return cardinality;
}

#endif
