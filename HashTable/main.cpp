#include "include/HashTable.h"
#include <iostream>
#include <string>

using namespace std;

struct var
{
	string name,type,kind;
	int n;	
};

int main()
{
	HashTable<var> H(10);
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
}
