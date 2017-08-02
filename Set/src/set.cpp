#ifndef SET_CPP
#define SET_CPP
#include "../include/set.h"

template<typename T>
UnorderedListSet<T>::UnorderedListSet()
{
    cardinality = 0;
}
// Default constructor; creates a new empty set

template<typename T>
bool UnorderedListSet<T>::isEmpty()
{
    return cardinality == 0;
}
// Returns true if the set is empty, false otherwise

template<typename T>
bool UnorderedListSet<T>::contains(T x)
{
    if(!this->isEmpty())
    {
        for(auto item : elements)
        {
            if(item == x)
                return true;
        }
        return false;
    }
    else
        return false;
}
// Returns true if the set contains x, false otherwise

template<typename T>
bool UnorderedListSet<T>::insert(T x)
{
    if(!this->contains(x))
    {
        elements.insert(x);
        cardinality++;
        return true;
    }
    else
        return false;
}
// Returns true if x is not in the element and is successfully inserted; false if present

template<typename T>
bool UnorderedListSet<T>::remove(T x)
{
    if(cardinality > 0)
    {
        for(typename List<T>::iterator it = elements.begin(); it != elements.end(); it++)
        {
            if (*it == x)
            {
                elements.remove(it);
                return true;
            }
        }
    }

    return false;
}
// Return ture if x is present in the set and removes it; false if absent

template<typename T>
typename UnorderedListSet<T>::iterator UnorderedListSet<T>::begin()
{
    return elements.begin();
}
// Returns a reference to the first element in the list

template<typename T>
typename UnorderedListSet<T>::iterator UnorderedListSet<T>::end()
{
    return elements.end();
}

template<typename T>
int UnorderedListSet<T>::size()
{
    return cardinality;
}

template<typename T>
HashSet<T>::HashSet(const int capacity): elements(capacity)
{
    cardinality = 0;
}
// Default constructor; creates a new empty set

template<typename T>
bool HashSet<T>::isEmpty() const
{
    return cardinality == 0;
}
// Returns true if the set is empty, false otherwise

template<typename T>
bool HashSet<T>::contains(const T x)
{
    return elements.contains(x);
}
// Returns true if the set contains x, false otherwise

template<typename T>
bool HashSet<T>::insert(const T x)
{
    if (!contains(x))
    {
        elements.insert(x);
        cardinality++;
        return true;
    }
    else
        return false;
}
// Returns true if x is not in the element and is successfully inserted; false if present

template<typename T>
bool HashSet<T>::remove(const T x)
{
    if(contains(x))
    {
        elements.remove(x);
        cardinality--;
        return true;
    }
    else
        return false;
}
// Return ture if x is present in the set and removes it; false if absent

template<typename T>
typename HashSet<T>::iterator HashSet<T>::begin()
{
    return elements.begin();
}
// Returns a reference to the first element in the list

template<typename T>
typename HashSet<T>::iterator HashSet<T>::end()
{
    return elements.end();
}
// Returns a reference to the end fo the list

template<typename T>
int HashSet<T>::size() const
{
    return cardinality;
}

template<typename T>
TreeSet<T>::TreeSet():cardinality(0)
{}
// Default constructor; creates a new empty set

template<typename T>
bool TreeSet<T>::isEmpty() const
{
    return cardinality == 0;
}
// Returns true if the set is empty, false otherwise

template<typename T>
bool TreeSet<T>::contains(const T x) const
{
    return elements.lookupNode(x) != nullptr;
}
// Returns true if the set contains x, false otherwise

    template<typename T>
bool TreeSet<T>::insert(const T x)
{
    if(!contains(x))
    {
        elements.insertNode(x);
        cardinality++;
        return true;
    }
    else
        return false;
}
// Returns true if x is not in the element and is successfully inserted; false if present

    template<typename T>
bool TreeSet<T>::remove(const T x)
{
    if(cardinality > 0 && contains(x))
    {
        elements.removeNode(x);
        cardinality--;
        return true;
    }
    else
        return false;
}
// Return ture if x is present in the set and removes it; false if absent

template<typename T>
int TreeSet<T>::size() const
{
    return cardinality;
}

// ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

template<typename T>
typename TreeSet<T>::iterator TreeSet<T>::begin()
{
    return elements.begin();
}
// Returns a reference to the first element in the list

template<typename T>
typename TreeSet<T>::iterator TreeSet<T>::last()
{
    return elements.last();
}

template<typename T>
typename TreeSet<T>::iterator TreeSet<T>::end()
{
    return elements.end();
}
// Returns a reference to the end fo the list

#endif
