#include <iostream>
#include "include/List.h"

using namespace std;

int main()
{
	List<int>* l = new List<int>();
	for(int i = 0; i < 100; i++)
		l->insert(l,i);
	List<int>* i = l->head();
	while(!l->finished(i))
	{
		cout << l->read(i) << " ";
		i = l->next(i);
	}
	cout << endl;

    for(List<int>* i = l->tail(); !l->finished(i); i = l->prev(i))
        cout << l->read(i) << " ";
    cout << endl;

    delete l;

}
