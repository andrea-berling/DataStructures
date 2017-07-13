#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "../include/queue.h"

template<typename T>
bool Queue<T>::isEmpty()
{
	return A.empty();
}
//returns true if the queue is empty

template<typename T>
void Queue<T>::enqueue(T v)
{
	A.insert(A.end(),v);
}
// enqueues v

template<typename T>
T Queue<T>::dequeue()
{
    List_iterator<T> it = A.begin();
	T t = *(A.begin());
    A.remove(it);
	return t;
}
// dequeues the element at the head of the queue

template<typename T>
T Queue<T>::top()
{
	return *(A.begin());
}
//returns the element at the head of the queue

#endif
