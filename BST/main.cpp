#include "include/bst.h"
#include "../Queue/include/queue.h"
#include <iostream>

using namespace std;

template<typename K, typename V>
void printTree(RBTree<K,V>* t);

template<typename K, typename V>
void visit_by_level(RBTree<K,V>* t);

template<typename K, typename V>
int height(RBTree<K,V>* t);

int main()
{
    RBTree<int,int> a;

    for (int j = 0; j < 20; j++)
    {
        a.insertNode(j,j);
    }

    printTree(a);
    printTree(&a);

    for (int j = 0; j < 20; j++)
    {
        a.removeNode(j);
    }

    printTree(a);
    printTree(&a);

    for (int j = 0; j < 20; j++)
    {
        a.insertNode(j,j);
    }

    printTree(a);
    printTree(&a);
    
    for (int j = 0; j < 20; j++)
    {
        a.removeNode(j);
    }

    printTree(a);

}

template<typename K, typename V>
void printTree(RBTree<K,V>* t)
{
    if (t != nullptr)
    {
        RBNode<K,V> *i;
        
        i = t->min();

        while(i != nullptr)
        {
            cout << i->getKey() << " ";
            i = t->successorNode(i);
        }

        cout << endl;
    }
}

template<typename K,typename V>
void visit_by_level(RBNode<K,V>* t, int spaces);

template<typename K,typename V>
void visit_by_level(RBTree<K,V>* t)
{
    if(t != nullptr && t->getRoot() != nullptr)
    {
        visit_by_level(t->getRoot(),0);
    }
}

template<typename K,typename V>
void visit_by_level(RBNode<K,V>* t, int spaces)
{
    Queue<RBNode<K,V>*> q;
    q.enqueue(t);
    while(!q.isEmpty())
    {
        RBNode<K,V>* u = q.dequeue();
        cout << u->getKey() << " " ;
        if(u->getLeft() != nullptr)
            q.enqueue(u->getLeft());
        if(u->getRight() != nullptr)
            q.enqueue(u->getRight());
    }
    cout << endl;
}

template<typename K, typename V>
int height(RBNode<K,V>* t)
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

template<typename K, typename V>
int height(RBTree<K,V>* t)
{
    return height(t->getRoot());
}
/*BST<int,int>* removeNode(BST<int,int>* T, int x)
{
    BST<int,int>* u = T->lookupNode(x);

    if (u != nullptr)
    {
        if (u->left() != nullptr && u->right() != nullptr)
        {
            BST<int,int>* s = u->right();
            while (s->left() != nullptr)
                s->setLeft(s);
            u->setKey(s->getKey());
            u->setValue(s->getValue());
            u = s;
            x = s->getKey();
        }
        BST<int,int>* t;
        if (u->left() != nullptr && u->right() == nullptr)
            t = u->left();
        else
            t = u->right();
        link(u->getParent(), t, x);
        if (u->getParent() == nullptr)
            T = t;
        free(u);
    }

    return T;
}*/
