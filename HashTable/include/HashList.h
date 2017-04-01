#ifndef HASHLIST_H
#define HASHLIST_H
#include "../../List/include/List.h"
#include "HashPair.h"
#include <string>

template<typename T>
class HashList
{
	private:
		List<HashPair<T>> l;
	public:

		List<HashPair<T>>* find(std::string key);
		// Returns an HashPair given a key if present, null if absent

		void insert(std::string key,T value);
		// Inserts a key-value pair in the HashList

		T* lookup(std::string key);
		// Returns a reference to an HashPair value given a key if present; null otherwise
		
		void remove(std::string key);
		// Removes an element given a key

		bool empty();
		// Returns true if the list is empty, false otherwise

};

#include "../src/HashList.cpp"

#endif
