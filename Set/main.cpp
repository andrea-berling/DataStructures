#include "include/set.h"
#include <iostream>

using namespace std;

int main()
{
    Set<int> a;

    for(int i = 0; i < 10; i++)
        a.insert(i);

    for(set_iterator<int> it = a.begin(); it != a.end(); it++)
        cout << *it << " ";

    cout << endl;

    for(int i = 0; i < 5; i++)
        a.remove(i);

    for(set_iterator<int> it = a.begin(); it != a.end(); it++)
        cout << *it << " ";

    cout << endl;
}
