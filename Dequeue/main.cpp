#include <iostream>
#include "include/dequeue.h"

using namespace std;

int main()
{
    Dequeue<int> q;
    for(int i = 0; i < 10; i++)
        q.push(i);
    cout << q.top() << endl;
    while(!q.empty())
        cout << q.pop() << " ";
    cout << endl;
    for(int i = 0; i < 10; i++)
        q.push(i);
    cout << q.last() << endl;
    while(!q.empty())
        cout << q.pop_last() << " ";
    cout << endl;
    for(int i = 0; i < 10; i++)
        q.push_back(i);
    cout << q.last() << endl;
    while(!q.empty())
        cout << q.pop_last() << " ";
    cout << endl;
}
