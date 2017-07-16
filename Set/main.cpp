#include <limits.h>
#include "include/set.h"
#include <iostream>

using namespace std;

class Integer
{
    private:

        int i;

    public:

        Integer()
        {
            i = INT_MAX;
        }

        Integer(int a):i(a){ };

        friend ostream& operator <<(ostream& out,Integer i);

        int getN()
        {
            return this->i;
        }

        friend bool operator ==(Integer n, Integer m);

};

ostream& operator <<(ostream& out,Integer i)
{
    out << i.i;
}

bool operator ==(Integer n, Integer m)
{
    return (n.i == m.i);
}

namespace std
{
    template <> struct hash<Integer>
    {
        size_t operator()(Integer i) const
        {
            return hash<int>()(i.getN());
        }
    };
}

int main()
{
    Hash::Set<Integer> a(193);

    for(int i = 0; i < 10; i++)
        a.insert(Integer(i));
    for(Hash::set_iterator<Integer> it = a.begin(); it != a.end(); it++)
        cout << *it << " ";

    cout << endl;

    for(int i = 0; i < 5; i++)
        a.remove(Integer(i));

    for(Hash::set_iterator<Integer> it = a.begin(); it != a.end(); it++)
        cout << *it << " ";

    cout << endl;

    Tree::Set<int> s;
    for(int i = 0; i < 100; i++)
    {
        s.insert(i);
    }

    for(Tree::set_iterator<int> it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for(Tree::set_iterator<int> it = s.begin(); it != s.end(); it++)
    {
        s.remove(*it);
    }

    for(Tree::set_iterator<int> it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
        cout << "BELLAA";
    }
    cout << endl;
}
