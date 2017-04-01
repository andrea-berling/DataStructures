#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashList.h"
#include <string>

template<typename T>
class HashTable
{
	protected:
		HashList<T>* entries;
		int m;	//table dimension
	public:

		HashTable(int capacity);
		//Creates a new hash table with given dimension

		~HashTable();
		//Destructor

		T* lookup(std::string k);
		//returns the value being searched if present, nil otherwise

		void insert(std::string key,T value);
		//Inserts the key-value pair into the table

		void remove(std::string key);
		//Given a key, it removes the key-pair value, if present

		int Hash(std::string key);
		//Hash function
};

#include "../src/HashTable.cpp"
#endif
