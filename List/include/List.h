#ifndef LIST_H
#define LIST_H

/**
 * Implementation of a parametric bidirectional circular linked list with sentinel
 */

template<typename T>
class List 
{
	private:

        struct Node
        {
            T value;
            Node *next,*prev;
        };

        Node* first;
        unsigned int size;

	public:

        class iterator
        {
            private:

                friend class List<T>;
                List<T>::Node* node;

            public:

                iterator(List<T>::Node* node): node(node) {}
                // Creates a new List_iterator given a node

                iterator(): node(nullptr) {}
                // Default constructor

                iterator(const iterator& it)
                {
                    this->node = it.node;
                }
                // Copy constructor

                T& operator*() const;
                // Returns the element pointed by the iterator

                bool operator==(const iterator rhs) const;
                // Returns true if the node pointed by the lhs iterator is the same as the one pointed by rhs

                bool operator!=(const iterator rhs) const;
                // Returns !(lhs == rhs)

                iterator& operator++();
                // Increments the iterator and returns the new iterator (prefix increment)

                iterator operator++(int);
                // Increments the iterator and returns the iterator as it was before the increment (postfix increment)

                iterator& operator--();
                // Decrements the iterator and returns the new iterator (prefix decrement)

                iterator operator--(int);
                // Decrements the iterator and returns the iterator as it was before the increment (postfix decrement)
        };

		List();
		// Creates an empty list

		List(const List& list);
		// Creates an empty list
        
		~List();
		// Destructor

        bool empty() const;
        // Returns true if the sequence is empty

        bool contains(const T v) const;
        // Returns true if the list contains v

        iterator begin() const;
        // Returns an iterator pointing to the first element

        iterator end() const;
        // Returns an iterator pointing to the end of the list
        // WARNING it does not contain an element, it points to the sentinel

        void insert(const iterator p,const T v);
        // Inserts v in position p

        void insert(const T v);
        // Inserts v at the beginning

        void remove(iterator& p);
        // removes v in position p

        void write(const iterator p,const T v) const;
        // writes v in position p

        unsigned int getSize() const;
        // Returns the size of the list in O(1) time

};

#include "../src/List.cpp"
#endif
