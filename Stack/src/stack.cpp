#ifndef STACK_CPP
#define STACK_CPP
#include "../include/stack.h"

template<typename T>
Stack<T>::Stack()
{
//	A = new List<T>();
}
// Constructs an empty stack

template<typename T>
Stack<T>::~Stack()
{
//	delete A;
}
// Destructor

template<typename T>
bool Stack<T>::isEmpty()
{
	return A.empty();
}
// returns true if the stack is empty

template<typename T>
void Stack<T>::push(T v)
{
	A.insert(A.head(),v);
}
// Pushes v on top of the stack

template<typename T>
T Stack<T>::pop()
{
	T v = A.read(A.head());
	A.remove(A.head());
	return v;
}
// Pops and return the element on top of the stack

template<typename T>
T Stack<T>::top()
{
	return A.read(A.head());
}
// Returns the element on top of the stack
#endif
