#include "include/bst.h"
#include "../Queue/include/queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void printTree(RBTree<T>& t);

template<typename T>
void visit_by_level(RBTree<T>& t);

template<typename T>
int height(RBTree<T>& t);

int main()
{
    RBTree<int> a;

    srand(time(0));
    for (int j = 0; j < 100000; j++)
    {
        a.insertNode(rand()% 100000);
    }

    //printTree(a);
    cout << "The height of the tree is " << height<int>(a) << endl;

    RBNode<int>* it = a.min();

    while(it != nullptr)
    {
        int rem = it->getKey();
        it = a.successorNode(it);
        a.removeNode(rem);
    }

    //printTree(a);

    //printTree(a);
    
    //printTree(a);

}

template<typename T>
void printTree(RBTree<T>& t)
{
    if (t.getRoot() != nullptr)
    {
        RBNode<T> *i = t.min();

        while(i != nullptr)
        {
            cout << i->getKey() << " ";
            i = t.successorNode(i);
        }

        cout << endl;
    }
}

template<typename T>
void visit_by_level(RBNode<T>* t, int spaces);

template<typename T>
void visit_by_level(RBTree<T>& t)
{
    if(t.getRoot != nullptr)
    {
        visit_by_level(t.getRoot(),0);
    }
}

template<typename T>
void visit_by_level(RBNode<T>* t, int spaces)
{
    Queue<RBNode<T>*> q;
    q.enqueue(t);
    while(!q.isEmpty())
    {
        RBNode<T>* u = q.dequeue();
        cout << u->getKey() << " " ;
        if(u->getLeft() != nullptr)
            q.enqueue(u->getLeft());
        if(u->getRight() != nullptr)
            q.enqueue(u->getRight());
    }
    cout << endl;
}

template<typename T>
int height(RBNode<T>* t)
{
    if(t == nullptr)
        return 0;
    else
    {
        int l = height(t->getLeft()) + 1;
        int r = height(t->getRight()) + 1;

        return r > l ? r : l;
    }
}

template<typename T>
int height(RBTree<T>& t)
{
    return height(t.getRoot());
}
