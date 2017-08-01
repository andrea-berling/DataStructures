#include "include/tree.h"
#include "../Queue/include/queue.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void preVisit(Tree<T>& t);

template<typename T>
void postVisit(Tree<T>& t);

template<typename T>
void inVisit(Tree<T>& t,int i);

template<typename T>
void levelVisit(Tree<T>& t);

int main()
{
	Tree<string> T("+");
	Tree<string>::Node* t2 = new Tree<string>::Node("x");
	Tree<string>::Node* t3 = new Tree<string>::Node("*");
	Tree<string>::Node* t4 = new Tree<string>::Node("f");
	Tree<string>::Node* t5 = new Tree<string>::Node("5");
	Tree<string>::Node* t6 = new Tree<string>::Node("2");
	Tree<string>::Node* t7 = new Tree<string>::Node("y");
	Tree<string>::Node* t8 = new Tree<string>::Node("-");
	Tree<string>::Node* t9 = new Tree<string>::Node("z");
	T.getRoot()->insertChild(t2);
	t2->insertSibling(t3);
	t3->insertChild(t4);
	t4->insertSibling(t5);
	t4->insertChild(t6);
	t6->insertSibling(t7);
	t7->insertSibling(t8);
	t8->insertChild(t9);
    cout << "Formula: x + f(2,y,-z)*5" << endl;
    cout << "Previsit:" << endl;
	preVisit(T);
    cout << "Postvisit:" << endl;
	postVisit(T);
    cout << "Invisit (i = 1):" << endl;
	inVisit(T,1);
    cout << "Visit by levels: " << endl;
	levelVisit(T);
}

template<typename T>
void preVisit(typename Tree<T>::Node* n, int level)
{
    for(int i = 0; i < level; i++)
        cout << "\t";
    cout << n->getValue() << endl;
    typename Tree<T>::Node* u = n->getChild();
    while (u != nullptr)
    {
        preVisit<T>(u,level + 1);
        u = u->getSibling();
    }
}

template<typename T>
void preVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
        preVisit<T>(t.getRoot(),0);
    cout << endl;
}

template<typename T>
void postVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
        postVisit<T>(t.getRoot());
    cout << endl;
}

template<typename T>
void postVisit(typename Tree<T>::Node* t)
{
    typename Tree<T>::Node* u = t->getChild();
    while (u != nullptr)
    {
        postVisit<T>(u);
        u = u->getSibling();
    }
    cout << t->getValue() << " ";
}

template<typename T>
void inVisit(Tree<T>& t,int i)
{
    if(t.getRoot() != nullptr)
        inVisit<T>(t.getRoot(),i);
    cout << endl;
}

template<typename T>
void inVisit(typename Tree<T>::Node* t,int i)
{
    int k = 0;
    typename Tree<T>::Node* u = t->getChild();
    while ((u != nullptr) && (k < i))
    {
        inVisit<T>(u,i);
        u = u->getSibling();
        k++;
    }
    cout << t->getValue() << " ";
    while (u != nullptr)
    {
        inVisit<T>(u,i);
        u = u->getSibling();
    }
}

template<typename T>
void levelVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
    {
        Queue<typename Tree<T>::Node*> q; 
        q.enqueue(t.getRoot());
        while (!q.isEmpty())
        {
            typename Tree<T>::Node* u = q.dequeue(); 
            cout << u->getValue() << " ";
            u = u->getChild();
            while (u != nullptr)
            {
                q.enqueue(u);
                u = u->getSibling();
            }
        }
        cout << endl;
    }
}
