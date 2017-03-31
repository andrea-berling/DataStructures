#include <iostream>
#include "include/queue.h"

using namespace std;

int main()
{
	Queue<int> q;
	for(int i = 0; i < 10000; i++)
		q.enqueue(i);
	while(!q.isEmpty())
		cout << q.dequeue() << " ";
	cout << endl;

}
