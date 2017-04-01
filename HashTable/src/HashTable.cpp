#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "../include/HashTable.h"

using namespace std;

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

#endif

