#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../../List/include/List.h"
#include <functional>

/**
 * Implementation of a Hashtable based on bucket lists made with Linkedlist
 */

template<typename K, typename V>
struct HashPair
{
    K key;
    V value;

    bool operator ==(const HashPair& rhs);
    bool operator ==(const K& key);
};

namespace std
{
    template<typename K, typename V> struct hash<HashPair<K,V>>
    {
        size_t operator()(HashPair<K,V> & p) const
        {
            return hash<K>()(p.key);
        }

    };
}

template<typename K, typename V>
struct HashTableType
{
    using ValueType = HashPair<K,V>;
};

template<typename K>
struct HashTableType<K,void>
{
    using ValueType = K;
};

template<typename K, typename V>
class HashTable
{
    protected:

        using ValueType = typename HashTableType<K,V>::ValueType;
        using ListType = List<ValueType>;

        ListType* entries;
        int m;	// table dimension

    public:

        class iterator
        {
            private:

                friend class HashTable;
                HashTable<K,V>* baseTable;
                int i;
                typename List<ValueType>::iterator it;
                typename List<ValueType>::iterator nextOccurrence();

            public:

                iterator():baseTable(nullptr),i(-1),it(typename List<ValueType>::iterator(nullptr)) {}

                iterator(HashTable<K,V>* table): baseTable(table),i(0),it(typename List<ValueType>::iterator(nullptr)) {}

                iterator(const iterator& it2): baseTable(it2.baseTable),i(it2.i),it(it2.it) {}

                bool operator ==(const iterator rhs);

                bool operator !=(const iterator rhs);

                iterator operator ++(); // prefix

                iterator operator ++( int ); // postfix

                ValueType& operator *() const;

        };

        HashTable(const int capacity);
        // Creates a new hash table with given dimension

        HashTable(HashTable& H);
        // Copy constructor

        ~HashTable();
        // Destructor
        
        bool contains(ValueType e) const;
        // Returns true if the hashtable contains k

        V lookup(const K k) const;
        // returns the value with key k if present, nil otherwise
        
        V operator [](const K k) const;
        // same as lookup, with a array like notation

        void insert(ValueType e);

        //void insert(const K key,const V value) const;
        // Inserts the key-value pair into the table

        void remove(const K key);
        // Given a key, it removes the key-pair value, if present

        int Hash(const long int key) const;
        // Hash function
        
        iterator begin();

        iterator end();
};

/*
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

            hash_iterator operator ++(); // prefix

            hash_iterator operator ++( int ); // postfix

            K operator *() const;
    };

    template<typename K>
    class HashTable
    {
        protected:

            HashList<K>* entries;
            int m;	// table dimension
            friend class hash_iterator<K>;

        public:

            HashTable();
            // Default constructor
            
            HashTable(const int capacity);
            // Creates a new hash table with given dimension

            ~HashTable();
            // Destructor

            bool contains(const K k) const;
            // Returns true if the table contains k

            void insert(const K key) const;
            // Inserts the key-value pair into the table

            void remove(const K key) const;
            // Given a key, it removes the key-pair value, if present

            int Hash(const long int key) const;
            // Hash function
    };

}
*/

#include "../src/HashTable.cpp"
#endif
