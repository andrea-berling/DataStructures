#ifndef HASHPAIR_CPP
#define HASHPAIR_CPP
#include "../include/HashPair.h"

using namespace std;

template<typename T>
HashPair<T>::HashPair()
{

}

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

#endif
