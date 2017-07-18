#ifndef LIST_H
#define LIST_H

/**
 * Implementation of a parametric bidirectional circular linked list with sentinel
 */

//Iterator class, used for iteration over the list
template<typename T>
class List_iterator;

//Base Node class, used for contaning the data
template<typename T>
class ListNode;

template<typename T>
class List 
{
	private:

        ListNode<T>* first;

	public:

        typedef List_iterator<T> iterator;

		List();
		// Creates an empty list

		~List();
		// Destructor

        bool empty();
        // Returns true if the sequence is empty

        bool finished(const iterator p);
        // Returns true if the iterator p has reached the end (or the beginning) of the list

        bool contains(const T v);
        // Returns true if the list contains v

        iterator begin();
        // Returns an iterator pointing to the first element

        iterator end();
        // Returns an iterator pointing to the end of the list
        // WARNING it does not contain an element, it points to the sentinel

        void insert(const iterator p,const T v);
        // Inserts v in position p

        void insert(const T v);
        // Inserts v at the beginning

        void remove(iterator& p);
        // removes v in position p

        void write(const iterator p,const T v);
        // writes v in position p
};

template<typename T>
class List_iterator
{
    private:

        friend class List<T>;
        ListNode<T>* node;

    public:

        typedef List_iterator<T> iterator;

        List_iterator(ListNode<T>* node);
        // Creates a new List_iterator given a node
        List_iterator();
        // Default constructor

        T& operator*();
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

template<typename T>
class ListNode
{
    private:
        
        friend class List_iterator<T>;
        friend class List<T>;
        ListNode *next,*prev;
        T value;
};

#include "../src/List.cpp"
#endif
