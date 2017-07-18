#include "include/priorityqueue.h"
#include <iostream>

using namespace std;

int main()
{
    PriorityQueue<int> q(20);

    // Test isEmpty() #1
    cout << q.isEmpty() << endl;
    // Test insert
    for(int i = 9; i >= 0; i--)
        q.insert(i,i);
    // Test min and deleteMin
    cout << q.min() << endl;
    for(int i = 0; i < 5; i++)
        cout << q.deleteMin() << " ";
    cout << endl;
    // Test isEmpty #2
    cout << q.isEmpty() << endl;
    // Test decrease
    PriorityItem<int> a = q.insert(19,19);
    //q.decrease(a,0);
    q.decrease(19,0);
    for(int i = 0; i < 6; i++)
        cout << q.deleteMin() << " ";
    cout << endl;
}
