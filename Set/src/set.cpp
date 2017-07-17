#ifndef SET_CPP
#define SET_CPP
#include "../include/set.h"

namespace list
{

    template<typename T>
    Set<T>::Set()
    {
        cardinality = 0;
    }
    // Default constructor; creates a new empty set

    template<typename T>
    bool Set<T>::isEmpty()
    {
        return cardinality == 0;
    }
    // Returns true if the set is empty, false otherwise

    template<typename T>
    bool Set<T>::contains(T x)
    {
        if(!this->isEmpty())
        {
            for(List_iterator<T> it = elements.begin(); it != elements.end(); it++)
            {
                if(*it == x)
                    return true;
            }

            return false;

        }
        else
            return false;
    }
    // Returns true if the set contains x, false otherwise

    template<typename T>
    bool Set<T>::insert(T x)
    {
        if(!this->contains(x))
        {
            elements->insert(x);
            cardinality++;

            return true;
        }
        else
            return false;
    }
    // Returns true if x is not in the element and is successfully inserted; false if present

    template<typename T>
    bool Set<T>::remove(T x)
    {
        bool done = false;

        for(List_iterator<T> it = elements.begin(); it != elements.end(); it++)
        {
            if (*it == x)
            {
                elements->remove(it);
                done = true;
            }
        }

        if(done)
            return true;
        else
            return false;
    }
    // Return ture if x is present in the set and removes it; false if absent

    // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

    template<typename T>
    set_iterator<T> Set<T>::begin()
    {
        set_iterator<T> it;

        return it.begin(&elements);
    }
    // Returns a reference to the first element in the list

    template<typename T>
    set_iterator<T> Set<T>::end()
    {
        set_iterator<T> it;

        return it.end(&elements);
    }
    // Returns a reference to the end fo the list

    template<typename T>
    set_iterator<T>::set_iterator()
    {
        baseList = nullptr;
        p = List_iterator<T>(nullptr);
    }

    template<typename T>
    set_iterator<T>::set_iterator(const set_iterator& it)
    {
        baseList = it.baseList;
        p = it.p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::begin(List<T>* l)
    {
        baseList = l;
        p = l->begin();
        
        return *this;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::end(List<T>* l)
    {
        if(baseList != l)
            baseList = l;

        p = l->end();

        return *this;
    }

    template<typename T>
    void set_iterator<T>::operator =(const set_iterator<T>& rightside)
    {
        baseList = rightside.baseList;
        p = rightside.p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator ++() //prefix
    {
        ++p;
        return p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator ++( int ) //postfix
    {
        set_iterator<T> oldit(*this);

        ++p;

        return oldit;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator --() //prefix
    {
        --p;

        return p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator --( int ) //postfix
    {
        set_iterator<T> oldit(*this);

        --p;

        return oldit;
    }

    template<typename T>
    T set_iterator<T>::operator *()
    {
        T e = T();
        if(!baseList->finished(p))
            e = *p;
        return e;
    }

    template<typename T>
    bool operator ==(const set_iterator<T>& it1, const set_iterator<T>& it2)
    {
        return (it1.baseList == it2.baseList) && (it1.p == it2.p);
    }

    template<typename T>
    bool operator !=(const set_iterator<T>& it1, const set_iterator<T>& it2)
    {
        return !(it1 == it2);
    }

    template<typename T>
    int Set<T>::size()
    {
        return cardinality;
    }
}

namespace Hash
{
    using keyOnly::HashTable;

    template<typename T>
    Set<T>::Set(int capacity):elements(capacity)
    {
        cardinality = 0;
    }
    // Default constructor; creates a new empty set

    template<typename T>
    bool Set<T>::isEmpty()
    {
        return cardinality == 0;
    }
    // Returns true if the set is empty, false otherwise

    template<typename T>
    bool Set<T>::contains(T x)
    {
        T test = T();
        T s = elements.lookup(x);
        if(s == test)
            return false;
        else
            return true;
    }
    // Returns true if the set contains x, false otherwise

    template<typename T>
    bool Set<T>::insert(T x)
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
    bool Set<T>::remove(T x)
    {
        if(contains(x))
        {
            elements.remove(x);
            return true;
        }
        else
            return false;
    }
    // Return ture if x is present in the set and removes it; false if absent

    // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

    template<typename T>
    set_iterator<T> Set<T>::begin()
    {
        set_iterator<T> it(&(this->elements));
        return it.begin(); 
    }
    // Returns a reference to the first element in the list

    template<typename T>
    set_iterator<T> Set<T>::end()
    {
        set_iterator<T> it(&(this->elements));
        return it.end(); 
    }
    // Returns a reference to the end fo the list

    template<typename T>
    int Set<T>::size()
    {
        return cardinality;
    }
}


namespace Tree
{

    template<typename T>
    set_iterator<T>::set_iterator()
    {
       baseTree = nullptr; 
       p = nullptr;
    }

    template<typename T>
    set_iterator<T>::set_iterator(const set_iterator& it)
    {
        baseTree = it.baseTree;
        p = it.p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::begin(RBTree<T>& t)
    {
        if(baseTree != &t)
            baseTree = &t;
        p = t.min();
        return *this;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::last(RBTree<T>& t)
    {
        if(baseTree != &t)
            baseTree = &t;
        p = t.max();
        return *this;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::end(RBTree<T>& t)
    {
        if(baseTree != &t)
            baseTree = &t;
        p = nullptr;
        return *this;
    }

    template<typename T>
    void set_iterator<T>::operator =(const set_iterator<T>& rightside)
    {
        baseTree = rightside.baseTree;
        p = rightside.p;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator ++() //prefix
    {
        p = baseTree->successorNode(p);
        return *this;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator ++( int ) //postfix
    {
        set_iterator<T> old(*this);
        p = baseTree->successorNode(p);
        return old;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator --() //prefix
    {
        p = baseTree->predecessorNode(p);
        return *this;
    }

    template<typename T>
    set_iterator<T> set_iterator<T>::operator --( int ) //postfix
    {
        set_iterator<T> old(*this);
        p = baseTree->predecessorNode(p);
        return old;
    }

    template<typename T>
    T set_iterator<T>::operator *()
    {
        return p->getKey();
    }

    template<typename T>
    bool operator ==(const set_iterator<T>& it1, const set_iterator<T>& it2)
    {
        return (it1.baseTree == it2.baseTree && it1.p == it2.p);
    }

    template<typename T>
    bool operator !=(const set_iterator<T>& it1, const set_iterator<T>& it2)
    {
        return !(it1 == it2);
    }

    template<typename T>
    Set<T>::Set():cardinality(0)
    {}
    // Default constructor; creates a new empty set

    template<typename T>
    bool Set<T>::isEmpty()
    {
        return cardinality == 0;
    }
    // Returns true if the set is empty, false otherwise

    template<typename T>
    bool Set<T>::contains(T x)
    {
        return elements.lookupNode(x) != nullptr;
    }
    // Returns true if the set contains x, false otherwise

    template<typename T>
    bool Set<T>::insert(T x)
    {
        if(!contains(x))
        {
            elements.insertNode(x);
            return true;
        }
        else
            return false;
    }
    // Returns true if x is not in the element and is successfully inserted; false if present

    template<typename T>
    bool Set<T>::remove(T x)
    {
        if(contains(x))
        {
            elements.removeNode(x);
            return true;
        }
        else
            return false;
    }
    // Return ture if x is present in the set and removes it; false if absent

    template<typename T>
    int Set<T>::size()
    {
        return cardinality;
    }

    // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

    template<typename T>
    set_iterator<T> Set<T>::begin()
    {
        set_iterator<T> it;
        return it.begin(elements);
    }
    // Returns a reference to the first element in the list

    template<typename T>
    set_iterator<T> Set<T>::last()
    {
        set_iterator<T> it;
        return it.last(elements);
    }

    template<typename T>
    set_iterator<T> Set<T>::end()
    {
        set_iterator<T> it;
        return it.end(elements);
    }
    // Returns a reference to the end fo the list
}

#endif
