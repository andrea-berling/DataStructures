#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "../include/HashTable.h"
#include <cmath>

using namespace std;

namespace stringKey
{

    template<typename T>
    HashPair<T>::HashPair()
    { }

    template<typename T>
    HashPair<T>::HashPair(string key,T value)
    {
        this->key = key;
        this->value = value;
    }

    template<typename T>
    string HashPair<T>::getKey()
    {
        return key;
    }
    // returns the key

    template<typename T>
    void HashPair<T>::setKey(string key)
    {
        this->key = key; 
    }
    // sets the key

    template<typename T>
    T HashPair<T>::getValue()
    {
        return value;
    }
    // returns the value

    template<typename T>
    void HashPair<T>::setValue(T v)
    {
        this->value = value;
    }
    // sets the value

    template<typename T>
    List<HashPair<T>>* HashList<T>::find(std::string key)
    {
        bool found = false;
        List<HashPair<T>>* e = nullptr;
        List<HashPair<T>>* i = l.head();

        while(!l.finished(i) && !found)
        {
            if(l.read(i).getKey() == key)
            {
                e = i;
                found = true;
            }
            
            i = l.next(i);
        }

        return e;
    }
    // Returns an HashPair given a key if present, null if absent

    template<typename T>
    void HashList<T>::insert(std::string key,T value)
    {
        List<HashPair<T>>* kv = find(key);
        if (kv != nullptr)
        {
            (l.read(kv)).setValue(value);
        }
        else
        {
            HashPair<T> k(key,value);
            l.insert(l.head(),k);
        }
    }
    // Inserts a key-value pair in the HashList
    
    template<typename T>
    T* HashList<T>::lookup(std::string key)
    {
        List<HashPair<T>>* kv = find(key);
        T* e = nullptr;

        if (kv != nullptr)
        {
            e = new T;
            *e = (l.read(kv)).getValue();
        }

        return e;
    }
    // Returns a reference to an HashPair value given a key if present; null otherwise

    template<typename T>
    void HashList<T>::remove(string key)
    {
        List<HashPair<T>>* item = find(key);
        if(item != nullptr)
            l.remove(item);
    }

    template<typename T>
    bool HashList<T>::empty()
    {
        return l.empty();
    }

    template<typename T>
    HashTable<T>::HashTable(int capacity)
    {
        entries = new HashList<T> [capacity];
        m = capacity;
    }
    //Creates a new hash table with given dimension

    template<typename T>
    HashTable<T>::~HashTable()
    {
        delete [] entries;
    }
    //Destructor

    template<typename T>
    T* HashTable<T>::lookup(string k)
    {
        int i = Hash(k);

        if (entries[i].empty())
            return nullptr;
        else
            return entries[i].lookup(k);
    }
    //returns the value being searched if present, nil otherwise

    template<typename T>
    void HashTable<T>::insert(string key,T value)
    {
        int i = Hash(key);
        
        entries[i].insert(key,value);
    }
    //Inserts the key-value pair into the table

    template<typename T>
    void HashTable<T>::remove(string key)
    {
        int k = Hash(key);	

        if (!entries[k].empty())
            entries[k].remove(key);

    }
    //Given a key, it removes the key-pair value, if present

    template<typename T>
    int HashTable<T>::Hash(string key)
    {
        int h = 0;
        string::iterator it;

        for(it = key.begin(); it != key.end(); ++it)
            h = (128 * h + (*it)) % m;

        return h;
    }
    //Hash function
}

namespace genKey
{

    template<typename K, typename V>
    HashPair<K,V>::HashPair()
    { }

    template<typename K, typename V>
    HashPair<K,V>::HashPair(K key,V value)
    {
        this->key = key;
        this->value = value;
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
    List<HashPair<K,V>>* HashList<K,V>::find(K key)
    {
        bool found = false;
        List<HashPair<K,V>>* e = nullptr;
        List<HashPair<K,V>>* i = l.head();

        while(!l.finished(i) && !found)
        {
            if(l.read(i).getKey() == key)
            {
                e = i;
                found = true;
            }
            
            i = l.next(i);
        }

        return e;
    }
    // Returns an HashPair given a key if present, null if absent

    template<typename K, typename V>
    void HashList<K,V>::insert(K key,V value)
    {
        List<HashPair<K,V>>* kv = find(key);

        if (kv != nullptr)
        {
            (l.read(kv)).setValue(value);
        }
        else
        {
            HashPair<K,V> k(key,value);
            l.insert(l.head(),k);
        }
    }
    // Inserts a key-value pair in the HashList
    
    template<typename K, typename V>
    V* HashList<K,V>::lookup(K key)
    {
        List<HashPair<K,V>>* kv = find(key);
        V* e = nullptr;

        if (kv != nullptr)
        {
            e = new V;
            *e = (l.read(kv)).getValue();
        }

        return e;
    }
    // Returns a reference to an HashPair value given a key if present; null otherwise

    template<typename K, typename V>
    void HashList<K,V>::remove(K key)
    {
        List<HashPair<K,V>>* item = find(key);
        if(item != nullptr)
            l.remove(item);
    }

    template<typename K, typename V>
    bool HashList<K,V>::empty()
    {
        return l.empty();
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
    V* HashTable<K,V>::lookup(K k)
    {
        int i = Hash(hash<K>()(k));

        if (entries[i].empty())
            return nullptr;
        else
            return entries[i].lookup(k);
    }
    //returns the value being searched if present, nil otherwise

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
}

namespace keyOnly
{

    template<typename K>
    List<K>* HashList<K>::find(K key)
    {
        bool found = false;
        List<K>* e = nullptr;
        List<K>* i = l.head();

        while(!l.finished(i) && !found)
        {
            if(l.read(i) == key)
            {
                e = i;
                found = true;
            }
            
            i = l.next(i);
        }

        return e;
    }
    // Returns an HashPair given a key if present, null if absent

    template<typename K>
    void HashList<K>::insert(K key)
    {
        List<K>* k = find(key);

        if (k == nullptr)
        {
            l.insert(l.head(),key);
        }

    }
    // Inserts a key-value pair in the HashList
    
    template<typename K>
    K* HashList<K>::lookup(K key)
    {
        List<K>* k = find(key);
        K* e = new K;

        if (k != nullptr)
            *e = l.read(k);
        else
        {
            delete e;
            e = nullptr;
        }

        return e;

    }
    // Returns a reference to an HashPair value given a key if present; null otherwise

    template<typename K>
    void HashList<K>::remove(K key)
    {
        List<K>* item = find(key);
        if(item != nullptr)
            l.remove(item);
    }

    template<typename K>
    bool HashList<K>::empty()
    {
        return l.empty();
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
    K* HashTable<K>::lookup(K k)
    {
        int i = Hash(hash<K>()(k));

        if (entries[i].empty())
            return nullptr;
        else
            return entries[i].lookup(k);
    }
    //returns the value being searched if present, nil otherwise

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

