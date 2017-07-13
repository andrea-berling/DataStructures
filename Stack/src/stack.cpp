#ifndef STACK_CPP
#define STACK_CPP
#include "../include/stack.h"

template<typename T>
bool Stack<T>::isEmpty()
{
	return A.empty();
}
// returns true if the stack is empty

template<typename T>
void Stack<T>::push(T v)
{
	A.insert(A.begin(),v);
}
// Pushes v on top of the stack

template<typename T>
T Stack<T>::pop()
{
    T item;
    List_iterator<T> it = A.begin();

    if(!isEmpty())
    {
        item = *(A.begin());
        A.remove(it);
    }

	return item;
}
// Pops and return the element on top of the stack

template<typename T>
T Stack<T>::top()
{
	return *(A.begin());
}
// Returns the element on top of the stack
#endif
