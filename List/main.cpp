#include <iostream>
#include "include/List.h"

using namespace std;

template<typename T>
void print(const List<T>& l);

template<typename T>
void print_backwards(const List<T>& l);

template<typename T>
void incrementByOne(const List<T>& l);

int main()
{
	List<int> l;
	for(int i = 0; i < 10; i++)
		l.insert(l.end(),i);
	List<int> l2(l);

    print(l);
    print_backwards(l);
    incrementByOne(l2);
    print(l2);
    print_backwards(l2);
}

template<typename T>
void print(const List<T>& l)
{
    for(typename List<T>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
    
    cout << endl;
}

template<typename T>
void print_backwards(const List<T>& l)
{
    for(typename List<T>::iterator it = --l.end(); it != l.end(); --it)
	{
		cout << *it << " ";
	}

    cout << endl;
}

template<typename T>
void incrementByOne(const List<T>& l)
{
    for(auto& n : l)
	{
        n++;
	}
}
