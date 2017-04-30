#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "../include/queue.h"

template<typename T>
Queue<T>::~Queue()
{
    A.destroy();
}
// Destructor

template<typename T>
bool Queue<T>::isEmpty()
{
	return A.empty();
}
//returns true if the queue is empty

template<typename T>
void Queue<T>::enqueue(T v)
{
	A.insert(&A,v);
}
// enqueues v

template<typename T>
T Queue<T>::dequeue()
{
	T t = A.read(A.head());
    A.remove(A.head());
	return t;
}
// dequeues the element at the head of the queue

template<typename T>
T Queue<T>::top()
{
	return A.read(A.head());
}
//returns the element at the head of the queue

#endif
