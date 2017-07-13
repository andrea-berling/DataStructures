#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "../include/HashTable.h"
#include <cmath>

using namespace std;

template<typename K, typename V>
HashPair<K,V>::HashPair()
{ 
    key = K();
    value = V();
}

template<typename K, typename V>
HashPair<K,V>::HashPair(K key,V value):key(key), value(value)
{
}

template<typename K, typename V>
K HashPair<K,V>::getKey()
{
    return key;
}
// returns the key

template<typename K, typename V>
void HashPair<K,V>::setKey(K key)
{
    this->key = key; 
}
// sets the key

template<typename K, typename V>
V HashPair<K,V>::getValue()
{
    return value;
}
// returns the value

template<typename K, typename V>
void HashPair<K,V>::setValue(V v)
{
    this->value = value;
}
// sets the value

template<typename K, typename V>
List_iterator<HashPair<K,V>> HashList<K,V>::find(K key)
{
    bool found = false;
    List_iterator<HashPair<K,V>> e(nullptr);
    List_iterator<HashPair<K,V>> i = l.begin();

    while(!l.finished(i) && !found)
    {
        if((*i).key == key)
        {
            e = i;
            found = true;
        }
        
        i++;
    }

    return e;
}
// Returns an HashPair given a key if present, null if absent

template<typename K, typename V>
void HashList<K,V>::insert(K key,V value)
{
    List_iterator<HashPair<K,V>> kv = find(key);
    HashPair<K,V> k(key,value);

    if (kv != List_iterator<HashPair<K,V>>(nullptr))
    {
        l.write(kv,k);
    }
    else
    {
        l.insert(k);
    }
}
// Inserts a key-value pair in the HashList

template<typename K, typename V>
V HashList<K,V>::lookup(K key)
{
    List_iterator<HashPair<K,V>> kv = find(key);
    V e;

    if (kv != List_iterator<HashPair<K,V>>(nullptr))
    {
        e = (*kv).value;
    }

    return e;
}
// Returns a reference to an HashPair value given a key if present; null otherwise

template<typename K, typename V>
void HashList<K,V>::remove(K key)
{
    List_iterator<HashPair<K,V>> item = find(key);
    if(item != List_iterator<HashPair<K,V>>(nullptr))
        l.remove(item);
}

template<typename K, typename V>
bool HashList<K,V>::empty()
{
    return l.empty();
}

template<typename K, typename V>
List_iterator<HashPair<K,V>> HashList<K,V>::begin()
{
    return l.begin();
}

template<typename K, typename V>
List_iterator<HashPair<K,V>> HashList<K,V>::end()
{
    return l.end();
}

template<typename K, typename V>
bool HashList<K,V>::finished(List_iterator<HashPair<K,V>> p)
{
    return l.finished(p);
}

template<typename K, typename V>
List_iterator<HashPair<K,V>> hash_iterator<K,V>::nextOccurrence()
{
    i++;

    it = List_iterator<HashPair<K,V>>(nullptr);

    while(i < baseTable->m && it == List_iterator<HashPair<K,V>>(nullptr))
    {
        if(baseTable->entries[i].empty())
            i++;
        else
            it = baseTable->entries[i].begin();
    }

    return it;
}

template<typename K, typename V>
hash_iterator<K,V>::hash_iterator()
{
    baseTable = nullptr;
    i = -1;
    it = List_iterator<HashPair<K,V>>(nullptr);
}

template<typename K, typename V>
hash_iterator<K,V>::hash_iterator(HashTable<K,V>* table)
{
    baseTable = table;
    i = -1;
    it = List_iterator<HashPair<K,V>>(nullptr);
}

template<typename K, typename V>
hash_iterator<K,V>::hash_iterator(const hash_iterator& it2)
{
    baseTable = it2.baseTable;
    i = it2.i;
    it = it2.it;
}

template<typename K, typename V>
bool operator ==(const hash_iterator<K,V>& it, const hash_iterator<K,V>& it2)
{
    return (it.baseTable == it2.baseTable && it.it == it2.it);
}

template<typename K, typename V>
bool operator !=(const hash_iterator<K,V>& it, const hash_iterator<K,V>& it2)
{
    return !(it == it2);
}

template<typename K, typename V>
hash_iterator<K,V> hash_iterator<K,V>::begin()
{
    if(i != 0)
        i = -1;

    hash_iterator<K,V> ret(*this);

    ret.nextOccurrence();

    return ret;
}

template<typename K, typename V>
hash_iterator<K,V> hash_iterator<K,V>::end()
{
    hash_iterator<K,V> ret(*this);
    ret.i = baseTable->m;
    ret.it = List_iterator<HashPair<K,V>>(nullptr);
    return ret;
}

template<typename K, typename V>
hash_iterator<K,V> hash_iterator<K,V>::operator ++() //prefix
{
    it++;

    if (baseTable->entries[i].finished(it))
    {
        it = nextOccurrence();
    }

    return *this;
}

template<typename K, typename V>
hash_iterator<K,V> hash_iterator<K,V>::operator ++( int ) //postfix
{
    hash_iterator<K,V> oldit(*this);

    ++(*this);

    return oldit;
}

template<typename K, typename V>
HashPair<K,V> hash_iterator<K,V>::operator *()
{
    return *it;
}

template<typename K, typename V>
HashTable<K,V>::HashTable(int capacity)
{
    entries = new HashList<K,V> [capacity];
    m = capacity;
}
//Creates a new hash table with given dimension

template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
    delete [] entries;
}
//Destructor

template<typename K, typename V>
V HashTable<K,V>::lookup(K k)
{
    int i = Hash(hash<K>()(k));
    V value = V();

    if (!entries[i].empty())
        value = entries[i].lookup(k);

    return value;
}
//returns the value being searched if present, nil otherwise

template<typename K,typename V>
bool HashTable<K,V>::contains(K k)
{
    int i = Hash(hash<K>()(k));
    if(entries[i].empty())
        return false;
    else
    {
        if(entries[i].find(k) == List_iterator<HashPair<K,V>>(nullptr))
            return false;
        else
            return true;
    }
}
//

template<typename K,typename V>
V HashTable<K,V>::operator [](K k)
{
    return lookup(k);
}

template<typename K, typename V>
void HashTable<K,V>::insert(K key,V value)
{
    int i = Hash(hash<K>()(key));
    
    entries[i].insert(key,value);
}
//Inserts the key-value pair into the table

template<typename K, typename V>
void HashTable<K,V>::remove(K key)
{
    int k = Hash(hash<K>()(key));	

    if (!entries[k].empty())
        entries[k].remove(key);

}
//Given a key, it removes the key-pair value, if present

template<typename K, typename V>
int HashTable<K,V>::Hash(long int key)
{
    return abs(key) % m;
}
//Hash function

template<typename K, typename V>
hash_iterator<K,V> HashTable<K,V>::begin()
{
    hash_iterator<K,V> ret(this);

    return ret.begin();
}

template<typename K, typename V>
hash_iterator<K,V> HashTable<K,V>::end()
{
    hash_iterator<K,V> ret(this);

    return ret.end();
}

namespace keyOnly
{

    template<typename K>
    List_iterator<K> HashList<K>::find(K key)
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
    void HashList<K>::insert(K key)
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
    void HashList<K>::remove(K key)
    {
        List_iterator<K> item = find(key);
        if(item != List_iterator<K>(nullptr))
            l.remove(item);
    }

    template<typename K>
    bool HashList<K>::empty()
    {
        return l.empty();
    }

    template<typename K>
    List_iterator<K> HashList<K>::begin()
    {
        return l.begin();
    }

    template<typename K>
    List_iterator<K> HashList<K>::end()
    {
        return l.end();
    }

    template<typename K>
    bool HashList<K>::finished(List_iterator<K> p)
    {
        return l.finished(p);
    }

    template<typename K>
    List_iterator<K> hash_iterator<K>::nextOccurrence()
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
    hash_iterator<K>::hash_iterator()
    {
        baseTable = nullptr;
        i = -1;
        it = List_iterator<K>(nullptr);
    }

    template<typename K>
    hash_iterator<K>::hash_iterator(HashTable<K>* table)
    {
        baseTable = table;
        i = -1;
        it = List_iterator<K>(nullptr);
    }

    template<typename K>
    hash_iterator<K>::hash_iterator(const hash_iterator& it2)
    {
        baseTable = it2.baseTable;
        i = it2.i;
        it = it2.it;
    }

    template<typename K>
    bool operator ==(const hash_iterator<K>& it, const hash_iterator<K>& it2)
    {
        return (it.baseTable == it2.baseTable && it.it == it2.it);
    }

    template<typename K>
    bool operator !=(const hash_iterator<K>& it, const hash_iterator<K>& it2)
    {
        return !(it == it2);
    }

    template<typename K>
    hash_iterator<K> hash_iterator<K>::begin()
    {
        if(i != 0)
            i = -1;

        hash_iterator<K> ret(*this);

        ret.nextOccurrence();

        return ret;
    }

    template<typename K>
    hash_iterator<K> hash_iterator<K>::end()
    {
        hash_iterator<K> ret(*this);
        ret.i = baseTable->m;
        ret.it = List_iterator<K>(nullptr);
        return ret;
    }

    template<typename K>
    hash_iterator<K> hash_iterator<K>::operator ++() //prefix
    {
        it++;

        if (baseTable->entries[i].finished(it))
        {
            it = nextOccurrence();
        }

        return *this;
    }

    template<typename K>
    hash_iterator<K> hash_iterator<K>::operator ++( int ) //postfix
    {
        hash_iterator<K> oldit(*this);

        ++(*this);

        return oldit;
    }

    template<typename K>
    K hash_iterator<K>::operator *()
    {
        
        return *it;
    }

    template<typename K>
    HashTable<K>::HashTable(int capacity)
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
        m = 1;
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
    bool HashTable<K>::contains(K k)
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
    void HashTable<K>::insert(K key)
    {
        int i = Hash(hash<K>()(key));
        
        entries[i].insert(key);
    }
    //Inserts the key-value pair into the table

    template<typename K>
    void HashTable<K>::remove(K key)
    {
        int k = Hash(hash<K>()(key));	

        if (!entries[k].empty())
            entries[k].remove(key);

    }
    //Given a key, it removes the key-pair value, if present

    template<typename K>
    int HashTable<K>::Hash(long int key)
    {
        return abs(key) % m;
    }
    //Hash function
}

#endif

