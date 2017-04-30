#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "../../List/include/List.h"

template<typename K, typename V>
class HashPair
{
    private:

        K key;
        V value;

    public:

        HashPair();
        // Default constructor
        
        HashPair(K key,V value);
        // constructs a new hash pair given a key and a value

        K getKey();
        // returns the key
        
        void setKey(K key);
        // sets the key
        
        V getValue();
        // returns the value
        
        void setValue(V v);
        // sets the value
        
};

template<typename K, typename V>
class HashList
{
    private:

        List<HashPair<K,V>> l;

    public:

        List<HashPair<K,V>>* find(K key);
        // Returns an HashPair given a key if present, null if absent
        
        void insert(K key,V value);
        // Inserts a key-value pair in the HashList

        V lookup(K key);
        // Returns a reference to an HashPair value given a key if present; null otherwise
        
        void remove(K key);
        // Removes an element given a key

        bool empty();
        // Returns true if the list is empty, false otherwise

        List<HashPair<K,V>>* head();

        List<HashPair<K,V>>* tail();

        List<HashPair<K,V>>* next(List<HashPair<K,V>>* p);

        bool finished(List<HashPair<K,V>>* p);

        HashPair<K,V> read(List<HashPair<K,V>>* p);
};

template<typename K, typename V>
class HashTable;

template<typename K, typename V>
class hash_iterator;

template<typename K, typename V>
bool operator ==(const hash_iterator<K,V>& it, const hash_iterator<K,V>& it2);

template<typename K, typename V>
bool operator !=(const hash_iterator<K,V>& it, const hash_iterator<K,V>& it2);

template<typename K, typename V>
class hash_iterator
{
    private:

        HashTable<K,V>* baseTable;
        int i;
        List<HashPair<K,V>>* it;
        List<HashPair<K,V>>* nextOccurrence();
        
    public:

        hash_iterator();

        hash_iterator(HashTable<K,V>* table);

        hash_iterator(const hash_iterator& it2);

        friend bool operator == <>(const hash_iterator& it, const hash_iterator& it2);

        friend bool operator != <>(const hash_iterator& it, const hash_iterator& it2);

        hash_iterator begin();

        hash_iterator end();

        hash_iterator operator ++(); //prefix

        hash_iterator operator ++( int ); //postfix

        HashPair<K,V> operator *();
};

template<typename K, typename V>
class HashTable
{
    protected:

        HashList<K,V>* entries;
        int m;	//table dimension
        friend class hash_iterator<K,V>;

    public:

        HashTable()
        {}

        HashTable(int capacity);
        //Creates a new hash table with given dimension

        ~HashTable();
        //Destructor

        V lookup(K k);
        //returns the value being searched if present, nil otherwise

        void insert(K key,V value);
        //Inserts the key-value pair into the table

        void remove(K key);
        //Given a key, it removes the key-pair value, if present

        int Hash(long int key);
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

            List<K>* find(K key);
            // Returns an HashPair given a key if present, null if absent
            
            void insert(K key);
            // Inserts a key-value pair in the HashList

            K lookup(K key);
            // Returns a reference to an HashPair value given a key if present; null otherwise
            
            void remove(K key);
            // Removes an element given a key

            bool empty();
            // Returns true if the list is empty, false otherwise

            List<K>* head();

            List<K>* tail();

            List<K>* next(List<K>* p);

            bool finished(List<K>* p);

            K read(List<K>* p);

    };

    template<typename K>
    class HashTable;

    template<typename K>
    class hash_iterator;

    template<typename K>
    bool operator ==(const hash_iterator<K>& it, const hash_iterator<K>& it2);

    template<typename K>
    bool operator !=(const hash_iterator<K>& it, const hash_iterator<K>& it2);

    template<typename K>
    class hash_iterator
    {
        protected:

            HashTable<K>* baseTable;
            int i;
            List<K>* it;
            List<K>* nextOccurrence();
            
        public:

            hash_iterator();

            hash_iterator(HashTable<K>* table);

            hash_iterator(const hash_iterator& it2);

            friend bool operator == <>(const hash_iterator& it, const hash_iterator& it2);

            friend bool operator != <>(const hash_iterator& it, const hash_iterator& it2);

            hash_iterator begin();

            hash_iterator end();

            hash_iterator operator ++(); //prefix

            hash_iterator operator ++( int ); //postfix

            K operator *();
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
            
            HashTable(int capacity);
            //Creates a new hash table with given dimension

            ~HashTable();
            //Destructor

            K lookup(K k);
            //returns the value being searched if present, nil otherwise

            void insert(K key);
            //Inserts the key-value pair into the table

            void remove(K key);
            //Given a key, it removes the key-pair value, if present

            int Hash(long int key);
            //Hash function
    };

}
#include "../src/HashTable.cpp"
#endif
