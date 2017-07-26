#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "../../List/include/List.h"

/**
 * Implementation of a Hashtable based on bucket lists made with Linkedlist
 */

template<typename K, typename V> class HashList;

template<typename K, typename V>
class HashPair
{
    private:

        friend class HashList<K,V>;
        K key;
        V value;

    public:

        HashPair();
        // Default constructor
        
        HashPair(const K key,const V value);
        // constructs a new hash pair given a key and a value

        K getKey() const;
        // returns the key
        
        void setKey(const K key);
        // sets the key
        
        V getValue() const;
        // returns the value
        
        void setValue(const V v);
        // sets the value
        
};

template<typename K, typename V>
class HashList
{
    private:

        List<HashPair<K,V>> l;

    public:

        List_iterator<HashPair<K,V>> find(const K key) const;
        // Returns an HashPair given a key if present, null if absent
        
        void insert(const K key,const V value) const;
        // Inserts a key-value pair in the HashList

        V lookup(const K key) const;
        // Returns a reference to an HashPair value given a key if present; null otherwise
        
        void remove(const K key) const;
        // Removes an element given a key

        bool empty() const;
        // Returns true if the list is empty, false otherwise

        List_iterator<HashPair<K,V>> begin() const;

        List_iterator<HashPair<K,V>> end() const;

        bool finished(List_iterator<HashPair<K,V>> const p) const;

};

template<typename K, typename V>
class HashTable;

template<typename K, typename V>
class hash_iterator;

template<typename K, typename V>
bool operator ==(const hash_iterator<K,V> it, const hash_iterator<K,V> it2);

template<typename K, typename V>
bool operator !=(const hash_iterator<K,V> it, const hash_iterator<K,V> it2);

template<typename K, typename V>
class hash_iterator
{
    private:

        HashTable<K,V>* baseTable;
        int i;
        List_iterator<HashPair<K,V>> it;
        List_iterator<HashPair<K,V>> nextOccurrence();
        
    public:

        hash_iterator();

        hash_iterator(HashTable<K,V>* table);

        hash_iterator(const hash_iterator& it2);

        friend bool operator == <>(const hash_iterator it, const hash_iterator it2);

        friend bool operator != <>(const hash_iterator it, const hash_iterator it2);

        hash_iterator begin();

        hash_iterator end();

        hash_iterator operator ++(); //prefix

        hash_iterator operator ++( int ); //postfix

        HashPair<K,V> operator *() const;
};

template<typename K, typename V>
class HashTable
{
    protected:

        HashList<K,V>* entries;
        int m;	//table dimension
        friend class hash_iterator<K,V>;

    public:

        HashTable(const int capacity);
        //Creates a new hash table with given dimension

        ~HashTable();
        //Destructor
        
        bool contains(const K k) const;
        //Returns true if the hashtable contains k

        V lookup(const K k) const;
        //returns the value being searched if present, nil otherwise
        
        V operator [](const K k) const;
        // same as lookup, with a array like notation

        void insert(const K key,const V value) const;
        //Inserts the key-value pair into the table

        void remove(const K key) const;
        //Given a key, it removes the key-pair value, if present

        int Hash(const long int key) const;
        //Hash function
        
        hash_iterator<K,V> begin();

        hash_iterator<K,V> end();
};

namespace keyOnly
{

    template<typename K>
    class HashList
    {
        private:

            List<K> l;

        public:

            List_iterator<K> find(const K key) const;
            // Returns an HashPair given a key if present, null if absent
            
            void insert(const K key) const;
            // Inserts a key-value pair in the HashList

            void remove(const K key) const;
            // Removes an element given a key

            bool empty() const;
            // Returns true if the list is empty, false otherwise

            List_iterator<K> begin() const;

            List_iterator<K> end() const;

            bool finished(List_iterator<K> const p) const;

    };

    template<typename K>
    class HashTable;

    template<typename K>
    class hash_iterator;

    template<typename K>
    bool operator ==(const hash_iterator<K> it, const hash_iterator<K> it2);

    template<typename K>
    bool operator !=(const hash_iterator<K> it, const hash_iterator<K> it2);

    template<typename K>
    class hash_iterator
    {
        protected:

            HashTable<K>* baseTable;
            int i;
            List_iterator<K> it;
            List_iterator<K> nextOccurrence();
            
        public:

            hash_iterator();

            hash_iterator(HashTable<K>* table);

            hash_iterator(const hash_iterator& it2);

            friend bool operator == <>(const hash_iterator it, const hash_iterator it2);

            friend bool operator != <>(const hash_iterator it, const hash_iterator it2);

            hash_iterator begin();

            hash_iterator end() const;

            hash_iterator operator ++(); //prefix

            hash_iterator operator ++( int ); //postfix

            K operator *() const;
    };

    template<typename K>
    class HashTable
    {
        protected:

            HashList<K>* entries;
            int m;	//table dimension
            friend class hash_iterator<K>;

        public:

            HashTable();
            //Default constructor
            
            HashTable(const int capacity);
            //Creates a new hash table with given dimension

            ~HashTable();
            //Destructor

            bool contains(const K k) const;
            // Returns true if the table contains k

            void insert(const K key) const;
            //Inserts the key-value pair into the table

            void remove(const K key) const;
            //Given a key, it removes the key-pair value, if present

            int Hash(const long int key) const;
            //Hash function
    };

}

#include "../src/HashTable.cpp"
#endif
