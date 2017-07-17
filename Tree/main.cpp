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
	TreeNode<string>* t2 = new TreeNode<string>("x");
	TreeNode<string>* t3 = new TreeNode<string>("*");
	TreeNode<string>* t4 = new TreeNode<string>("f");
	TreeNode<string>* t5 = new TreeNode<string>("5");
	TreeNode<string>* t6 = new TreeNode<string>("2");
	TreeNode<string>* t7 = new TreeNode<string>("y");
	TreeNode<string>* t8 = new TreeNode<string>("-");
	TreeNode<string>* t9 = new TreeNode<string>("z");
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
void preVisit(TreeNode<T>* n, int level)
{
    for(int i = 0; i < level; i++)
        cout << "\t";
    cout << n->getValue() << endl;
    TreeNode<T>* u = n->getChild();
    while (u != nullptr)
    {
        preVisit(u,level + 1);
        u = u->getSibling();
    }
}

template<typename T>
void preVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
        preVisit(t.getRoot(),0);
    cout << endl;
}

template<typename T>
void postVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
        postVisit(t.getRoot());
    cout << endl;
}

template<typename T>
void postVisit(TreeNode<T>* t)
{
    TreeNode<T>* u = t->getChild();
    while (u != nullptr)
    {
        postVisit(u);
        u = u->getSibling();
    }
    cout << t->getValue() << " ";
}

template<typename T>
void inVisit(Tree<T>& t,int i)
{
    if(t.getRoot() != nullptr)
        inVisit(t.getRoot(),i);
    cout << endl;
}

template<typename T>
void inVisit(TreeNode<T>* t,int i)
{
    int k = 0;
    TreeNode<T>* u = t->getChild();
    while ((u != nullptr) && (k < i))
    {
        inVisit(u,i);
        u = u->getSibling();
        k++;
    }
    cout << t->getValue() << " ";
    while (u != nullptr)
    {
        inVisit(u,i);
        u = u->getSibling();
    }
}

template<typename T>
void levelVisit(Tree<T>& t)
{
    if(t.getRoot() != nullptr)
    {
        Queue<TreeNode<T>*> q; 
        q.enqueue(t.getRoot());
        while (!q.isEmpty())
        {
            TreeNode<T>* u = q.dequeue(); 
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
