#ifndef DEQUEUE_CPP
#define DEQUEUE_CPP
#include "../include/dequeue.h"

template<typename T>
bool Dequeue<T>::empty()
{
    return l.empty();
}
// Returns true if empty

template<typename T>
void Dequeue<T>::push(T v)
{
    l.insert(l.begin(),v);
}
// Pushes v on top of the dequeue

template<typename T>
void Dequeue<T>::push_back(T v)
{
    l.insert(l.end(),v);
}
// Pushes v at the end of the dequeue

template<typename T>
T Dequeue<T>::pop()
{
    T item;
    if(!empty())
    {
        List_iterator<T> it = l.begin();
        item = *it;
        l.remove(it);
    }

    return item;
}
// Pops the element on top

template<typename T>
T Dequeue<T>::pop_last()
{
    T item;
    if(!empty())
    {
        List_iterator<T> it = --l.end();
        item = *it;
        l.remove(it);
    }

    return item;
}
// Pops the element at the end

template<typename T>
T& Dequeue<T>::top()
{
    return *(l.begin());
}
// Returns the element on top

template<typename T>
T& Dequeue<T>::last()
{
    return *(--l.end());
}
// Returns the element at the end

#endif
