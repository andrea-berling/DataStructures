#include <iostream>
#include "include/List.h"

using namespace std;

int main()
{
	List<int>* l = new List<int>();
	for(int i = 0; i < 10; i++)
		l->insert(l,i);
	List<int>* i = l->head();
	while(!l->finished(i))
	{
		cout << l->read(i) << " ";
		i = l->next(i);
	}
	cout << endl;
	i = l->tail();
	while(!l->finished(i))
	{
		cout << l->read(i) << " ";
		i = l->prev(i);
	}
	cout << endl;

}
