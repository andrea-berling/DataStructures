#include <iostream>
#include "include/List.h"

using namespace std;

int main()
{
	List<int> l;
    List_iterator<int> it;
	for(int i = 0; i < 10; i++)
		l.insert(i);
    for(it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}

    cout << endl;

    for(it = --l.end(); it != l.end(); it--)
	{
		cout << *it << " ";
	}
	cout << endl;
}
