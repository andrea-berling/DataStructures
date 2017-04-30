#ifndef LIST_H
#define LIST_H

template<typename T>
class List 
{
	private:

		List *Next,*Prev;
		T value;

	public:

		List();
		// Creates an empty list

		~List();
		// Destructor

        bool empty();
        // Returns true if the sequence is empty

        bool finished(List* p);
        // Returns true if the list is finished

        List* head();
        // Returns the position of the first element

        List* tail();
        // Returns the position of the last element

        List* next(List* p);
        // Returns the position of p's next element

        List* prev(List* p);
        // Returns the position of p's prev element

        List* insert(List* p,T v);
        // Inserts v in position p
        // returns the position of the new inserted element 

        List* remove(List* p);
        // removes v in position p
        // returns the position of p's next element
        
        T read(List* p);
        // returns the element in position p

        void write(List* p,T v);
        // writes v in position p

        void destroy();
        // Frees the memory occupied by the entire list
};

#include "../src/List.cpp"
#endif
