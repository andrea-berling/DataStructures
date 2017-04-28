#include "include/set.h"
#include <iostream>

using namespace std;

class Integer
{
    private:

        int i;

    public:

        Integer()
        { }

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
    using namespace Hash;

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
}
