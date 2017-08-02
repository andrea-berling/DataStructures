#ifndef SET_H
#define SET_H
#include "../../List/include/List.h"
#include "../../HashTable/include/HashTable.h"
#include "../../BST/include/bst.h"

template<typename T>
class UnorderedListSet
{
    private:

        List<T> elements;
        int cardinality;

    public:

        using iterator = typename List<T>::iterator;

        UnorderedListSet();
        // Default constructor; creates a new empty set

        bool isEmpty();
        // Returns true if the set is empty, false otherwise

        bool contains(T x);
        // Returns true if the set contains x, false otherwise

        bool insert(T x);
        // Returns true if x is not in the element and is successfully inserted; false if present

        bool remove(T x);
        // Return ture if x is present in the set and removes it; false if absent

        int size();

        // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

        iterator begin();
        // Returns a reference to the first element in the list

        iterator end();
        // Returns a reference to the end fo the list
};


template<typename T>
class HashSet
{
    private:

        HashTable<T,void> elements; 
        int cardinality;

    public:

        using iterator = typename HashTable<T,void>::iterator;

        HashSet(const int capacity);
        // Default constructor; creates a new empty set

        bool isEmpty() const;
        // Returns true if the set is empty, false otherwise

        bool contains(const T x);
        // Returns true if the set contains x, false otherwise

        bool insert(const T x);
        // Returns true if x is not in the element and is successfully inserted; false if present

        bool remove(const T x);
        // Return ture if x is present in the set and removes it; false if absent

        int size() const;

        iterator begin();
        // Returns a reference to the first element in the list

        iterator end();
        // Returns a reference to the end fo the list

};

template<typename T>
class TreeSet
{
    private:

        RBTree<T> elements;
        int cardinality;

    public:

        using iterator = typename RBTree<T>::iterator;

        TreeSet();
        // Default constructor; creates a new empty set

        bool isEmpty() const;
        // Returns true if the set is empty, false otherwise

        bool contains(const T x) const;
        // Returns true if the set contains x, false otherwise

        bool insert(const T x);
        // Returns true if x is not in the element and is successfully inserted; false if present

        bool remove(const T x);
        // Return ture if x is present in the set and removes it; false if absent

        int size() const;

        // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

        iterator begin();
        // Returns a reference to the first element in the list

        iterator last();
        // Returns a reference to the last element of the set

        iterator end();
        // Returns a reference to the end of the list

};

#include "../src/set.cpp"

#endif
