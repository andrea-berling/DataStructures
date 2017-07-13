#include <iostream>
#include "include/List.h"

using namespace std;

int main()
{
	List<int> l;
    List<int>::iterator it;
	for(int i = 0; i < 100; i++)
		l.insert(i);
    for(it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}

    cout << endl;

    for(it = --l.end(); it != --l.begin(); it--)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(int i = 0; i < 100; i++)
        cout << l.contains(i+1) << " " ;
    cout << endl;
}
