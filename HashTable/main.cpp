#include "include/HashTable.h"
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;

struct var
{
	string name,type,kind;
	int n;	
};

class Node {

    private:

        string name;
        int weight;

    public:

        Node()
        {
            name = ""; 
            weight = INT_MAX;
        }

        Node(const Node& m)
        {
            name = m.name;
            weight = m.weight;
        }

        Node(string name, int weight): name(name), weight(weight)
        {}

        string getName()
        {
            return this->name;
        }

        void setName(string name)
        {
            this->name = name;
        }

        void setWeight(int weight)
        {
            this->weight = weight;
        }

        int getWeight()
        {
            return this->weight;
        }

        void print()
        {
            cout << name << " " << weight << endl;
        }

        friend bool operator ==(const Node& n1, const Node& n2);
        
};

namespace std
{
    template <> struct hash<Node>
    {
        size_t operator()(Node & n) const
        {
            return hash<string>()(n.getName());
        }
    };
}

bool operator ==(const Node& n1, const Node& n2)
{
    return (n1.name == n2.name) && (n1.weight == n2.weight);
}

int main()
{

    HashTable<string,Node> H(17);

    H.insert({"numero 1",{"numero 1", 1}});
    H.insert({"numero 2",{"numero 2", 2}});
    H.insert({"numero 3",{"numero 3", 3}});
    H.insert({"numero 4",{"numero 4", 4}});

    HashTable<string,Node> H2(H);

    Node i;

    i = H.lookup("numero 1");
    i.print();
    i = H.lookup("numero 4");
    i.print();
    i = H["numero 2"];
    i.print();
    i = H["numero 3"];
    i.print();

    H.remove("numero 1");
    i = H.lookup("numero 1");
    if(i == Node())
        cout << "Element not found" << endl;


    
    for(HashTable<string,Node>::iterator it = H.begin(); it != H.end(); it++)
        (*it).value.print();

    cout << "H2" << endl;
    for(auto p : H2)
        p.value.print();
      
}
