#ifndef STACK_H
#define STACK_H
#include "../../List/include/List.h"

/**
 * Implementation of a LinkedList based parametric Stack
 */

template<typename T>
class Stack
{
	private:

		List<T> A;

	public:

		bool isEmpty();
		// returns true if the stack is empty

		void push(T v);
		// Pushes v on top of the stack
		
		T pop();
		// Pops and return the element on top of the stack
		
		T top();
		// Returns the element on top of the stack
};

#include "../src/stack.cpp"

#endif
