#include "include/tree.h"
#include "../Queue/include/queue.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void preVisit(Tree<T> t);

template<typename T>
void postVisit(Tree<T> t);

template<typename T>
void inVisit(Tree<T> t,int i);

template<typename T>
void levelVisit(Tree<T> t);

int main()
{
	Tree<string> t1("+");
	Tree<string> t2("x");
	Tree<string> t3("*");
	Tree<string> t4("f");
	Tree<string> t5("5");
	Tree<string> t6("2");
	Tree<string> t7("y");
	Tree<string> t8("-");
	Tree<string> t9("z");
	t1.insertChild(&t2);
	t2.insertSibling(&t3);
	t3.insertChild(&t4);
	t4.insertSibling(&t5);
	t4.insertChild(&t6);
	t6.insertSibling(&t7);
	t7.insertSibling(&t8);
	t8.insertChild(&t9);
	preVisit(t1);
	cout << endl;
	postVisit(t1);
	cout << endl;
	inVisit(t1,1);
	cout << endl;
	levelVisit(t1);
	cout << endl;
}

template<typename T>
void preVisit(Tree<T> t)
{
    cout << t.read() << " ";
    Tree<T>* u = t.leftmostChild();
    while (u != nullptr)
    {
	preVisit(*u);
	u = u->rightSibling();
    }
}

template<typename T>
void postVisit(Tree<T> t)
{
    Tree<T>* u = t.leftmostChild();
    while (u != nullptr)
    {
	postVisit(*u);
	u = u->rightSibling();
    }
    cout << t.read() << " ";
}

template<typename T>
void inVisit(Tree<T> t,int i)
{
    int k = 0;
    Tree<T>* u = t.leftmostChild();
    while ((u != nullptr) && (k < i))
    {
	inVisit(*u,i);
	u = u->rightSibling();
	k++;
    }
    cout << t.read() << " ";
    while (u != nullptr)
    {
	inVisit(*u,i);
	u = u->rightSibling();
    }
}

template<typename T>
void levelVisit(Tree<T> t)
{
   Queue<Tree<T>*> q; 
   q.enqueue(&t);
   while (!q.isEmpty())
   {
      Tree<T>* u = q.dequeue(); 
      cout << u->read() << " ";
      u = u->leftmostChild();
      while (u != nullptr)
      {
	 q.enqueue(u);
	 u = u->rightSibling();
      }
   }
}
