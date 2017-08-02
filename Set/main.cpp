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

        Integer operator++(int)
        {
            Integer old = *this;
            i++;
            return old;
        }

        friend bool operator ==(Integer n, Integer m);
        friend bool operator <(Integer n, Integer m);
        friend bool operator >(Integer n, Integer m);
        friend bool operator !=(Integer n, Integer m);

};

ostream& operator <<(ostream& out,Integer i)
{
    out << i.i;
}

bool operator ==(Integer n, Integer m)
{
    return (n.i == m.i);
}

bool operator <(Integer n, Integer m)
{
    return (n.i < m.i);
}

bool operator >(Integer n, Integer m)
{
    return (n.i > m.i);
}

bool operator !=(Integer n, Integer m)
{
    return !(n == m);
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
    UnorderedListSet<Integer> set;

    for(int i = 0; i < 10; i++)
        set.insert(Integer(i));

    cout << "Unordered List set" << endl;

    for(auto element : set)
    {
        cout << element << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++)
        set.remove(Integer(i));
    
    for(UnorderedListSet<Integer>::iterator it = set.begin(); it != set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    HashSet<Integer> hashSet(193);
    cout << "Hash set" << endl;

    for(int i = 0; i < 10; i++)
        hashSet.insert(Integer(i));
    for(HashSet<Integer>::iterator it = hashSet.begin(); it != hashSet.end(); it++)
        cout << *it << " ";

    cout << endl;

    for(int i = 0; i < 5; i++)
        hashSet.remove(Integer(i));

    for(Integer& i: hashSet)
    {
        i++;
    }

    for(Integer i : hashSet)
        cout << i << " ";
    cout << endl;

    TreeSet<Integer> s;
    cout << "Tree set" << endl;

    for(int i = 0; i < 10; i++)
    {
        s.insert(Integer(i));
    }

    for(TreeSet<Integer>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++)
        s.remove(Integer(i));
    
    for(auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}
