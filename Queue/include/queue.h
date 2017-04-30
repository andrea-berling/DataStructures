#ifndef QUEUE_H
#define QUEUE_H
#include "../../List/include/List.h"

template<typename T>
class Queue
{
	private:

		List<T> A;

	public:

        ~Queue();
        // Destructor

		bool isEmpty();
		//returns true if the queue is empty
	
		void enqueue(T v);
		// enqueues v
		
		T dequeue();
		// dequeues the element at the head of the queue

		T top();
		//returns the element at the head of the queue

};

#include "../src/queue.cpp"

#endif
