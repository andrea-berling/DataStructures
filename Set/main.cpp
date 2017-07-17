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
    Hash::Set<Integer> a(193);
    cout << "Hash set" << endl;

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

    Tree::Set<Integer> s;
    cout << "Tree set" << endl;

    for(int i = 0; i < 10; i++)
    {
        s.insert(Integer(i));
    }

    for(Tree::set_iterator<Integer> it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++)
        s.remove(Integer(i));
    
    for(Tree::set_iterator<Integer> it = s.last(); it != s.end(); it--)
    {
        cout << *it << " ";
    }
    cout << endl;

}
