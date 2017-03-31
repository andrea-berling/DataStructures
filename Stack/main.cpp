#include "include/stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> s;	
	for (int i = 0; i < 10; i++)
		s.push(i);
	while(!s.isEmpty())
		cout << s.pop() << " ";
	cout << endl;
	for (int i = 10; i > 0; i--)
		s.push(i);
	while(!s.isEmpty())
		cout << s.pop() << " ";
	cout << endl;
}
