#ifndef SET_H
#define SET_H
#include "../../List/include/List.h"
#include "../../HashTable/include/HashTable.h"

namespace list
{
    template<typename T> class set_iterator;

    template<typename T>
    bool operator ==(const set_iterator<T>& it1, const set_iterator<T>& it2);

    template<typename T>
    bool operator !=(const set_iterator<T>& it1, const set_iterator<T>& it2);

    template<typename T>
    class set_iterator
    {
        private:

            List<T>* baseList;
            List<T>* p;

        public:

            set_iterator();

            set_iterator(const set_iterator& it);

            set_iterator begin(List<T>* l);

            set_iterator end(List<T>* l);

            void operator =(const set_iterator& rightside);
            
            set_iterator operator ++(); //prefix

            set_iterator operator ++( int ); //postfix

            set_iterator operator --(); //prefix

            set_iterator operator --( int ); //postfix

            T operator *();

            friend bool operator == <>(const set_iterator<T>& it1, const set_iterator<T>& it2);

            friend bool operator != <>(const set_iterator<T>& it1, const set_iterator<T>& it2);

    };

    template<typename T>
    class Set
    {
        private:

            List<T>* elements;
            int cardinality;
            friend class set_iterator<T>;

        public:

            Set();
            // Default constructor; creates a new empty set

            bool isEmpty();
            // Returns true if the set is empty, false otherwise
            
            bool contains(T x);
            // Returns true if the set contains x, false otherwise

            T lookup(T x);
            // Return a pointer to the element x if present, nil otherwise
            
            bool insert(T x);
            // Returns true if x is not in the element and is successfully inserted; false if present

            bool remove(T x);
            // Return ture if x is present in the set and removes it; false if absent

            int size();

            // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

            set_iterator<T> begin();
            // Returns a reference to the first element in the list

            set_iterator<T> end();
            // Returns a reference to the end fo the list
            
    };
}

namespace Hash
{

/*    template<typename T> class Set;
    template<typename T> class set_iterator;

    template<typename T>
    bool operator ==(const set_iterator<T>& it1, const set_iterator<T>& it2);

    template<typename T>
    bool operator !=(const set_iterator<T>& it1, const set_iterator<T>& it2);

    template<typename T>
    class set_iterator : public keyOnly::hash_iterator<T>
    {
        public:

            set_iterator();

            set_iterator(Set<T>* s);

            set_iterator(const set_iterator& it);

            set_iterator(const keyOnly::hash_iterator<T>& it);

    };
    */

    template<typename T>
    using set_iterator = typename keyOnly::hash_iterator<T>;

    template<typename T>
    class Set
    {
        private:

            keyOnly::HashTable<T> elements; 
            int cardinality;

        public:

            Set()
            {}

            Set(int capacity);
            // Default constructor; creates a new empty set

            ~Set();
            // Destructor

            bool isEmpty();
            // Returns true if the set is empty, false otherwise
            
            bool contains(T x);
            // Returns true if the set contains x, false otherwise

            T lookup(T x);
            // Return a pointer to the element x if present, nil otherwise
            
            bool insert(T x);
            // Returns true if x is not in the element and is successfully inserted; false if present

            bool remove(T x);
            // Return ture if x is present in the set and removes it; false if absent

            int size();

            // ACCESSOR METHODS NEEDED FOR ITERATION OVER THE SET; GONNA CHANGE THEM

            set_iterator<T> begin();
            // Returns a reference to the first element in the list

            set_iterator<T> end();
            // Returns a reference to the end fo the list
            
    };

}

#include "../src/set.cpp"

#endif
