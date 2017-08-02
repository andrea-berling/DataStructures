#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "../include/HashTable.h"
#include <functional>
#include <cmath>

using namespace std;

template<typename K, typename V>
bool HashPair<K,V>::operator ==(const HashPair<K,V>& rhs)
{
    return rhs.key == key;
}

template<typename K, typename V>
bool HashPair<K,V>::operator ==(const K& key)
{
    return this->key == key;
}

template<typename K, typename V>
typename HashTable<K,V>::ListType::iterator HashTable<K,V>::iterator::nextOccurrence()
{
    i++;

    it = typename ListType::iterator(nullptr);

    while(i < baseTable->m && it == typename ListType::iterator(nullptr))
    {
        if(baseTable->entries[i].empty())
            i++;
        else
            it = baseTable->entries[i].begin();
    }

    return it;
}

template<typename K, typename V>
bool HashTable<K,V>::iterator::operator ==(const typename HashTable<K,V>::iterator rhs)
{
    return (baseTable == rhs.baseTable && it == rhs.it);
}

template<typename K, typename V>
bool HashTable<K,V>::iterator::operator !=(const typename HashTable<K,V>::iterator rhs)
{
    return !(*this == rhs);
}

template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::iterator::operator ++() //prefix
{
    it++;

    if(it == baseTable->entries[i].end())
    {
        it = nextOccurrence();
    }

    return *this;
}

template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::iterator::operator ++( int ) //postfix
{
    HashTable<K,V>::iterator oldit(*this);

    ++(*this);

    return oldit;
}

template<typename K, typename V>
typename HashTable<K,V>::ValueType& HashTable<K,V>::iterator::operator *() const
{
    return *it;
}

template<typename K, typename V>
HashTable<K,V>::HashTable(const int capacity)
{
    entries = new ListType [capacity];
    m = capacity;
}
//Creates a new hash table with given dimension

template<typename K, typename V>
HashTable<K,V>::HashTable(HashTable& H)
{
    m = H.m;
    entries = new ListType [m];
    for(auto p : H) // OBVIOUSLY TO FIX
        insert(p);
}

//Creates a new hash table with given dimension
template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
    delete [] entries;
}
//Destructor

template<typename K, typename V>
V HashTable<K,V>::lookup(const K k) const
{
    int i = Hash(hash<K>()(k));
    V value = V();

    if (!entries[i].empty())
    {
        typename List<ValueType>::iterator it = entries[i].begin();
        bool found = false;
        while (it != entries[i].end() && !found)
        {
            if((*it).key == k)
            {
                value = (*it).value;
                found = true;
            }
            it++;
        }
    }

    return value;
}
//returns the value being searched if present, nil otherwise

template<typename K,typename V>
bool HashTable<K,V>::contains(ValueType e) const
{
    int i = Hash(hash<ValueType>()(e));
    if(entries[i].empty())
        return false;
    else
    {
        typename List<ValueType>::iterator it = entries[i].begin();
        bool found = false;
        while (it != entries[i].end() && !found)
        {
            if(*it == e)
                return true;
            it++;
        }
        return false;
    }
}
//

template<typename K,typename V>
V HashTable<K,V>::operator [](const K k) const
{
    return lookup(k);
}

template<typename K,typename V>
void HashTable<K,V>::insert(ValueType e)
{
    int i = Hash(hash<ValueType>()(e));
    typename ListType::iterator it = this->entries[i].begin();
    bool found = false;
    while(it != this->entries[i].end() && !found)
    {
        if(*it == e) // here the == operator returns true if two hashPairs have the same key
        {
            found = true;
        }
        it++;
    }
    if(!found)
        this->entries[i].insert(e);
}
//Inserts the key-value pair into the table

/*
template<typename K, typename V>
void HashTable<K,V>::insert(const K key,const V value) const
{
    int i = Hash(hash<K>()(key));
    typename ListType::iterator it = entries[i].begin();
    bool found = false;
    while(it != entries[i].end() && !found)
    {
        if((*it).key == key)
        {
            (*it).value = value;
            found = true;
        }
        it++;
    }
    if(!found)
        entries[i].insert({key,value});
}
//Inserts the key-value pair into the table
*/

template<typename K, typename V>
void HashTable<K,V>::remove(const K key)
{
    int k = Hash(hash<K>()(key));	

    if (!entries[k].empty())
    {
        typename ListType::iterator it = entries[k].begin();
        bool removed = false;
        while(it != entries[k].end() && !removed)
        {
            if(*it == key)
            {
                entries[k].remove(it);
                removed = true;
            }
            it++;
        }
    }
}
//Given a key, it removes the key-pair value, if present

/*
template<typename K, typename V>
void HashTable<K,V>::remove(ValueType e)
{
    int k = Hash(hash<ValueType>()(e));	

    if (!entries[k].empty())
    {
        typename ListType::iterator it = entries[k].begin();
        bool removed = false;
        while(it != entries[k].end() && !removed)
        {
            if(*it == e)
            {
                entries[k].remove(it);
                removed = true;
            }
            it++;
        }
    }
}
//Given a key, it removes the key-pair value, if present
*/

template<typename K, typename V>
int HashTable<K,V>::Hash(const long int key) const
{
    return abs(key) % m;
}
//Hash function

template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::begin()
{
    HashTable<K,V>::iterator ret(this);
    ret.i = -1;
    ret.it = ret.nextOccurrence();

    return ret;
}

template<typename K, typename V>
typename HashTable<K,V>::iterator HashTable<K,V>::end()
{
    HashTable<K,V>::iterator ret(this);
    ret.i = m - 1;
    ret.it = typename ListType::iterator(nullptr);

    return ret;
}

/*
namespace keyOnly
{

    template<typename K>
    List_iterator<K> HashList<K>::find(const K key) const
    {
        bool found = false;
        List_iterator<K> e = List_iterator<K>(nullptr);

        if(!l.empty())
        {
            List_iterator<K> i = l.begin();

            while(!l.finished(i) && !found)
            {
                if(*i == key)
                {
                    e = i;
                    found = true;
                }
                
                i++;
            }
        }

        return e;
    }
    // Returns an HashPair given a key if present, null if absent

    template<typename K>
    void HashList<K>::insert(const K key) const
    {
        List_iterator<K> k = find(key);

        if (k == List_iterator<K>(nullptr))
        {
            l.insert(key);
        }
        else
        {
            l.write(k,key);
        }

    }
    // Inserts a key-value pair in the HashList
    
    
    template<typename K>
    K HashList<K>::lookup(K key)
    {
        List_iterator<K> k = find(key);
        K e;

        if (k != List_iterator<K>(nullptr))
            e = *k;

        return e;
    }
    // Returns a reference to an HashPair value given a key if present; null otherwise

    template<typename K>
    void HashList<K>::remove(const K key) const
    {
        List_iterator<K> item = find(key);
        if(item != List_iterator<K>(nullptr))
            l.remove(item);
    }

    template<typename K>
    bool HashList<K>::empty() const
    {
        return l.empty();
    }

    template<typename K>
    List_iterator<K> HashList<K>::begin() const
    {
        return l.begin();
    }

    template<typename K>
    List_iterator<K> HashList<K>::end() const
    {
        return l.end();
    }

    template<typename K>
    bool HashList<K>::finished(const List_iterator<K> p) const
    {
        return l.finished(p);
    }

    template<typename K>
    List_iterator<K> HashTable<K,V>::iterator<K>::nextOccurrence()
    {
        i++;

        it = List_iterator<K>(nullptr);

        while(i < baseTable->m && it == List_iterator<K>(nullptr))
        {
            if(baseTable->entries[i].empty())
                i++;
            else
                it = baseTable->entries[i].begin();
        }

        return it;
    }

    template<typename K>
    HashTable<K,V>::iterator<K>::HashTable<K,V>::iterator()
    {
        baseTable = nullptr;
        i = -1;
        it = List_iterator<K>(nullptr);
    }

    template<typename K>
    HashTable<K,V>::iterator<K>::HashTable<K,V>::iterator(HashTable<K>* table)
    {
        baseTable = table;
        i = -1;
        it = List_iterator<K>(nullptr);
    }

    template<typename K>
    HashTable<K,V>::iterator<K>::HashTable<K,V>::iterator(const HashTable<K,V>::iterator& it2)
    {
        baseTable = it2.baseTable;
        i = it2.i;
        it = it2.it;
    }

    template<typename K>
    bool operator ==(const HashTable<K,V>::iterator<K> it, const HashTable<K,V>::iterator<K> it2)
    {
        return (it.baseTable == it2.baseTable && it.it == it2.it);
    }

    template<typename K>
    bool operator !=(const HashTable<K,V>::iterator<K> it, const HashTable<K,V>::iterator<K> it2)
    {
        return !(it == it2);
    }

    template<typename K>
    HashTable<K,V>::iterator<K> HashTable<K,V>::iterator<K>::begin()
    {
        if(i != 0)
            i = -1;

        HashTable<K,V>::iterator<K> ret(*this);

        ret.nextOccurrence();

        return ret;
    }

    template<typename K>
    HashTable<K,V>::iterator<K> HashTable<K,V>::iterator<K>::end() const
    {
        HashTable<K,V>::iterator<K> ret(*this);
        ret.i = baseTable->m;
        ret.it = List_iterator<K>(nullptr);
        return ret;
    }

    template<typename K>
    HashTable<K,V>::iterator<K> HashTable<K,V>::iterator<K>::operator ++() //prefix
    {
        it++;

        if (baseTable->entries[i].finished(it))
        {
            it = nextOccurrence();
        }

        return *this;
    }

    template<typename K>
    HashTable<K,V>::iterator<K> HashTable<K,V>::iterator<K>::operator ++( int ) //postfix
    {
        HashTable<K,V>::iterator<K> oldit(*this);

        ++(*this);

        return oldit;
    }

    template<typename K>
    K HashTable<K,V>::iterator<K>::operator *() const
    {
        
        return *it;
    }

    template<typename K>
    HashTable<K>::HashTable(const int capacity)
    {
        entries = new HashList<K> [capacity];
        m = capacity;
    }
    //Creates a new hash table with given dimension

    template<typename K>
    HashTable<K>::~HashTable()
    {
        delete [] entries;
    }
    //Destructor

    template<typename K>
    HashTable<K>::HashTable()
    {
        entries = nullptr;
        m = -1;
    }

    
    template<typename K>
    K HashTable<K>::lookup(K k)
    {
        K key = K();
        int i = Hash(hash<K>()(k));

        if (!entries[i].empty())
            key = entries[i].lookup(k);

        return key;
    }
    //returns the value being searched if present, nil otherwise
   

    template<typename K>
    bool HashTable<K>::contains(const K k) const
    {
        int i = Hash(hash<K>()(k));
        if(entries[i].empty())
            return false;
        else
        {
            if(entries[i].find(k) == List_iterator<K>(nullptr))
                return false;
            else
                return true;
        }
    }

    template<typename K>
    void HashTable<K>::insert(const K key) const
    {
        int i = Hash(hash<K>()(key));
        
        entries[i].insert(key);
    }
    //Inserts the key-value pair into the table

    template<typename K>
    void HashTable<K>::remove(const K key) const
    {
        int k = Hash(hash<K>()(key));	

        if (!entries[k].empty())
            entries[k].remove(key);

    }
    //Given a key, it removes the key-pair value, if present

    template<typename K>
    int HashTable<K>::Hash(const long int key) const
    {
        return abs(key) % m;
    }
    //Hash function
}
*/

#endif

