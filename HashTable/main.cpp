#include "include/HashTable.h"
#include <iostream>
#include <string>

using namespace std;

struct var
{
	string name,type,kind;
	int n;	
};

class Node: public Hashable
{
    private:

        string name;
        int weight;

    public:

        Node()
        {}

        Node(string name, int weight): name(name), weight(weight)
        {}

        virtual long int hashCode()
        {
            return (long int) std::hash<string>()(name);
        }

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

bool operator ==(const Node& n1, const Node& n2)
{
    return (n1.name == n2.name) && (n1.weight == n2.weight);
}

int main()
{
    stringKey::HashTable<var> H(10);
	H.insert("x",{"x","int","argument",2});
	H.insert("y",{"y","string","argument",2});
	H.insert("z",{"z","pointer","var",2});
	H.insert("t",{"t","BankAccount","var",4});

	var* item;
	item = H.lookup("x");
	cout << item->name << " " << item->type << " " << item->kind << " " << item-> n << endl;
	item = H.lookup("y");
	cout << item->name << " " << item->type << " " << item->kind << " " << item-> n << endl;
	item = H.lookup("z");
	cout << item->name << " " << item->type << " " << item->kind << " " << item-> n << endl;
	item = H.lookup("t");
	cout << item->name << " " << item->type << " " << item->kind << " " << item-> n << endl;
	H.remove("t");
	item = H.lookup("t");
	if (item == nullptr)
		cout << "Element not found" << endl;

    genKey::HashTable<Node,Node> H2(10);

    H2.insert({"1",1},{"numero 1", 1});
    H2.insert({"2",2},{"numero 2", 2});
    H2.insert({"3",3},{"numero 3", 3});
    H2.insert({"4",4},{"numero 4", 4});

    Node* i;

    i = H2.lookup({"1",1});
    i->print();
    i = H2.lookup(Node("4",4));
    i->print();
    i = H2.lookup(Node("3",3));
    i->print();
    i = H2.lookup(Node("2",2));
    i->print();

    H2.remove(Node("1",1));
    i = H2.lookup(Node("1",1));
    if (i == nullptr)
        cout << "Element not found" << endl;
    else
        cout << "Error" << endl;
}
