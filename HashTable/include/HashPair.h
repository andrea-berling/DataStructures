#ifndef HASHPAIR_H
#define HASHPAIR_H
#include <string>

template<typename T>
class HashPair
{
	private:
		std::string key;
		T value;
	public:

		HashPair();
		// Default constructor
		
		HashPair(std::string key,T value);
		// constructs a new hash pair given a key and a value

		std::string getKey();
		// returns the key
		
		void setKey(std::string key);
		// sets the key
		
		T getValue();
		// returns the value
		
		void setValue(T v);
		// sets the value
		
};

#include "../src/HashPair.cpp"

#endif
