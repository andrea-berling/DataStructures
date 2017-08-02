#include "include/bst.h"
#include "../Queue/include/queue.h"
#include <iostream>

using namespace std;

template<typename T>
void listTree(RBTree<T>& t);

template<typename T>
void printTree(RBTree<T>& t);

template<typename T>
void printTree(typename RBTree<T>::Node* t,int level);

template<typename T>
void visit_by_level(RBTree<T>& t);

template<typename T>
int height(RBTree<T>& t);

int main()
{
    RBTree<int> a;

    
    for (int i = 0; i < 10; i++)
    {
        a.insertNode(i);
    }
    
    cout << "Visit by order of keys: ";
    listTree(a);
    cout << "Visit by levels: ";
    visit_by_level(a);
    cout << "Previsit with colors: " << endl;
    printTree(a);
    cout << "The height of the tree is " << height<int>(a) << endl;

    RBTree<int>::Node* it = a.min();

    while(it != nullptr)
    {
        int rem = it->key;
        it = a.successorNode(it);
        a.removeNode(rem);
    }
}

template<typename T>
void listTree(RBTree<T>& t)
{
    /*
    if (t.getRoot() != nullptr)
    {
        typename RBTree<T>::Node *i = t.min();

        while(i != nullptr)
        {
            cout << i->key << " ";
            i = t.successorNode(i);
        }

        cout << endl;
    }
    */

    /*
    for(typename RBTree<T>::iterator it = t.begin(); it != t.end(); ++it)
        cout << *it << " ";
    */

    for(T& item : t)
    {
        item++;
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void visit_by_level(typename RBTree<T>::Node* t, int spaces);

template<typename T>
void visit_by_level(RBTree<T>& t)
{
    if(t.getRoot() != nullptr)
    {
        visit_by_level<T>(t.getRoot(),0);
    }
}

template<typename T>
void visit_by_level(typename RBTree<T>::Node* t, int spaces)
{
    Queue<typename RBTree<T>::Node*> q;
    q.enqueue(t);
    while(!q.isEmpty())
    {
        typename RBTree<T>::Node* u = q.dequeue();
        cout << u->key << " " ;
        if(u->left != nullptr)
            q.enqueue(u->left);
        if(u->right != nullptr)
            q.enqueue(u->right);
    }
    cout << endl;
}

template<typename T>
int height(typename RBTree<T>::Node* t)
{
    if(t == nullptr)
        return 0;
    else
    {
        int l = height<T>(t->left) + 1;
        int r = height<T>(t->right) + 1;

        return r > l ? r : l;
    }
}

template<typename T>
int height(RBTree<T>& t)
{
    return height<T>(t.getRoot());
}

template<typename T>
void printTree(RBTree<T>& t)
{
    printTree<T>(t.getRoot(),0);
}

template<typename T>
void printTree(typename RBTree<T>::Node* t,int level)
{
    if(t != nullptr)
    {
        for(int i = 0; i < level; i++)
            cout << "\t";
        char color = t->color == BLACK ? 'B' : 'R';
        cout << color << ":" << t->key << endl;
        printTree<T>(t->left,level + 1);
        printTree<T>(t->right,level + 1);
    }
}
