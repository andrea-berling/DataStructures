#ifndef HASHLIST_CPP
#define HASHLIST_CPP
#include "../include/HashList.h"

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

#endif
