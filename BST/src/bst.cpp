#ifndef BST_CPP
#define BST_CPP
#include "../include/bst.h"
#define DEBUG

template<typename K,typename V>
RBNode<K,V>::RBNode()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}
// Default constructor

template<typename K,typename V>
RBNode<K,V>::RBNode(K key): key(key)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}
// Creates a node given a key

template<typename K,typename V>
RBNode<K,V>::RBNode(K key,V value):key(key),value(value)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}
// Creates a node given a key

template<typename K,typename V>
K RBNode<K,V>::getKey()
{
    return key;
}
// Key getter

template<typename K,typename V>
V RBNode<K,V>::getValue()
{
    return value;
}
// Value getter

template<typename K,typename V>
RBNode<K,V>* RBNode<K,V>::getParent()
{
    return parent;
}

template<typename K,typename V>
RBNode<K,V>* RBNode<K,V>::getLeft()
{
    return left;
}

template<typename K,typename V>
RBNode<K,V>* RBNode<K,V>::getRight()
{
    return right;
}

template<typename K,typename V>
color_t RBNode<K,V>::getColor()
{
    return color;
}

template<typename K,typename V>
void link(RBNode<K,V>* p,RBNode<K,V>* u,K x)
{
    if(u != nullptr)
        u->parent = p;
    if(p != nullptr)
    {
        if(p->key > x)
            p->left = u;
        else if (p->key < x) // just to check that x is not equal to p->key
            p->right = u;
    }
}

template<typename K,typename V>
RBTree<K,V>::RBTree()
{
    root = nullptr;
}

template<typename K,typename V>
RBTree<K,V>::RBTree(K key)
{
    root = new RBNode<K,V>(key);
}

template<typename K,typename V>
RBTree<K,V>::RBTree(K key,V value)
{
    root = new RBNode<K,V>(key,value);
}

template<typename K,typename V>
RBTree<K,V>::RBTree(RBNode<K,V>& u)
{
    root = &u;
}

template<typename K,typename V>
RBTree<K,V>::~RBTree()
{
    if (root != nullptr)
    {
        RBNode<K,V>* old = min();
        RBNode<K,V>* next = successorNode(old);

        while(next != nullptr)
        {
            delete old;
            old = next;
            next = successorNode(next);
        }

        delete old; // deletes the last element
    }
}
// Creates a new tree given an existing node

template<typename K,typename V>
RBNode<K,V>* RBTree<K,V>::lookupNode(K x)
{
    RBNode<K,V> *T = root;
    while(T != nullptr && T->key != x)
        T = x < T->key ? T->left : T->right;
    return T;
}

template<typename K,typename V>
void RBTree<K,V>::insertNode(RBNode<K,V>* u)
{
    if(u != nullptr)
       insertNode(u->key,u->value);
}

template<typename K,typename V>
void RBTree<K,V>::insertNode(K x,V v)
{
    RBNode<K,V> *p = nullptr;
    RBNode<K,V> *u = root;
    while(u != nullptr && u->key != x)
    {
        p = u;
        u = x < u->key? u->left : u->right;
    }
    if (u != nullptr && u->key == x)
        u->value = v;
    else
    {
        RBNode<K,V>* n = new RBNode<K,V>(x,v);
        link(p,n,x);
        balanceInsert(n);
        while(n->parent != nullptr)
            n = n->parent;
        root = n;
    }
}

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::min()
{
    if(root == nullptr)
        return root;
    else
    {
        RBNode<K,V>* t = root;
        while(t->left != nullptr)
            t = t->left;
        return t;
    }
}

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::max()
{
    if(root == nullptr)
        return root;
    else
    {
        RBNode<K,V>* t = root;
        while(t->right != nullptr)
            t = t->right;
        return t;
    }
}

template<typename K,typename V>
void RBTree<K,V>::removeNode(K x)
{
    RBNode<K,V>* u = lookupNode(x);
    if(u != nullptr)
    {
        if(u->left != nullptr && u->right != nullptr)
        {
            RBNode<K,V>* s = u->right;
            while(s->left != nullptr)
                s = s->left;
            u->key = s->key;
            u->value = s->value;
            x = s->key;
            u = s;
        }

        RBNode<K,V>* t;
        if(u->left != nullptr && u->right == nullptr)
            t = u->left;
        else
            t = u->right;
        link(u->parent,t,x);

        if(u->parent != nullptr)
        {
            if(u->color == BLACK)
            {
                if(t != nullptr)
                    balanceDelete(t);
                else
                {
                    RBNode<K,V>* dummy = new RBNode<K,V>();
                    dummy->parent = u->parent;
                    if(u->parent->right == nullptr)
                        u->parent->right = dummy;
                    else
                        u->parent->left = dummy;
                    balanceDelete(dummy);
                    if(dummy == u->parent->left)
                        u->parent->left = nullptr;
                    else
                        u->parent->right = nullptr;
                    delete dummy;
                }
            }
            if(u->parent == nullptr)
                root = t;
            while(root->parent != nullptr) // if the balanceDelete procedure modifes the root, it has to be restored
                root = root->parent;
        }
        else
            root = nullptr;

        delete u;

    }
}

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::successorNode(RBNode<K,V>* t)
{
    if(t == nullptr)
        return t;
    if (t->right != nullptr)
    {
        t = t->right;               // searches the min of the right subtree
        while(t->left != nullptr)
            t = t->left;
        return t;
    }
    RBNode<K,V>* p = t->parent;
    while(p != nullptr && t == p->right)
    {
        t = p;
        p = p->parent;
    }
    return p;
}

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::predecessorNode(RBNode<K,V>* t)
{
    if(t == nullptr)
       return t; 
    if(t->left != nullptr)
    {
        t = t->left;            //searche the max of the left subtree
        while(t->right != nullptr)
            t = t->right;
    }

    RBNode<K,V>* p = t->parent;
    while(p != nullptr && t == p->left)
    {
        t = p;
        p = p->parent;
    }
    return p;
}

//OLD STUFF

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::rotateLeft(RBNode<K,V>* x)
{
    RBNode<K,V>* y = x->right;
    RBNode<K,V>* p = x->parent;

    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->left = x;
    x->parent = y;
    y->parent = p;
    if (p != nullptr)
    {
        if (p->left == x)
            p->left = y;
        else
            p->right = y;
    }

    return y;
}

template<typename K, typename V>
RBNode<K,V>* RBTree<K,V>::rotateRight(RBNode<K,V>* x)
{
    RBNode<K,V>* y = x->left;
    RBNode<K,V>* p = x->parent;

    x->left = y->right;
    if (y->right != nullptr)
        y->right->parent = x;
    y->right = x;
    x->parent = y;
    y->parent = p;
    if (p != nullptr)
    {
        if (p->right == x)
            p->right = y;
        else
            p->left = y;
    }

    return y;
}

template<typename K, typename V>
void RBTree<K,V>::balanceInsert(RBNode<K,V>* t)
{
    t->color = RED;

    while (t != nullptr)
    {
        RBNode<K,V>* p = t->parent;
        RBNode<K,V>* n = p != nullptr ? p->parent : nullptr;
        RBNode<K,V>* z = n == nullptr ? nullptr : (n->left == p ? n->right : n->left) ;
        if (p == nullptr)
        {
            t->color = BLACK;
            t = nullptr;
        }
        else if (p->color == BLACK)
        {
            t = nullptr;
        }
        else if (z != nullptr && z->color == RED)
        {
            p->color = z->color = BLACK;
            n->color = RED;
            t = n;
        }
        else
        {
            if (t == p->right && p == n->left)
            {
                rotateLeft(p);
                t = p;
            }
            else if (t == p->left && p == n->right)
            {
                rotateRight(p);
                t = p;
            }
            else
            {
                if (t == p->left && p == n->left)
                    rotateRight(n);
                else if (t == p->right && p == n->right)
                    rotateLeft(n);
                p->color = BLACK;
                n->color = RED;
                t = nullptr;
            }
        }
    }
}

template<typename K, typename V>
void RBTree<K,V>::balanceDelete(RBNode<K,V>* t)
{
    while(t != root && t->color == BLACK)
    {
        RBNode<K,V>* p = t->parent;
        if (t == p->left)
        {
            RBNode<K,V>* f = p->right;
            RBNode<K,V>* ns = f->left;
            RBNode<K,V>* nd = f->right;
            if (f->color == RED)
            {
                p->color = RED;
                f->color = BLACK;
                rotateLeft(p);
            }
            else
            {
                if ((ns == nd && nd == nullptr) || (nd != nullptr && (nd->color == BLACK)) || (ns != nullptr && ns->color == BLACK) || (ns != nullptr && ns != nullptr) && (nd->color == BLACK))
                {
                    f->color = RED;
                    t = p;
                }
                else if ((ns != nullptr && ns->color == RED) && (nd == nullptr || nd->color == BLACK))
                {
                    ns->color = BLACK;
                    f->color = RED;
                    rotateRight(f);
                }
                else if (nd->color == RED)
                {
                    f->color = p->color;
                    p->color = BLACK;
                    nd->color = BLACK;
                    rotateLeft(p);
                    t = root;
                }
            }
        }
        else
        {
            RBNode<K,V>* f = p->left;
            RBNode<K,V>* ns = f->right;
            RBNode<K,V>* nd = f->left;
            if (f != nullptr)
            {
                if (f->color == RED)
                {
                    p->color = RED;
                    f->color = BLACK;
                    rotateRight(p);
                }
                else
                {
                    if ((ns == nd && nd == nullptr) || (nd != nullptr && (nd->color == BLACK)) || (ns != nullptr && ns->color == BLACK) || (ns != nullptr && ns != nullptr) && (nd->color == BLACK))
                    {
                        f->color = RED;
                        t = p;
                    }
                    else if ((ns != nullptr && ns->color == RED) && (nd == nullptr || nd->color == BLACK))
                    {
                        ns->color = BLACK;
                        f->color = RED;
                        rotateLeft(f);
                    }
                    else if (nd->color == RED)
                    {
                        f->color = p->color;
                        p->color = BLACK;
                        nd->color = BLACK;
                        rotateRight(p);
                        t = root;
                    }
                }
            }
        }
    }
    if (t != nullptr)
        t->color = BLACK;
}

template<typename K,typename V>
RBNode<K,V>* RBTree<K,V>::getRoot()
{
    return root;
}

#ifdef DEBUG
#include <iostream>
template<typename K,typename V>
void printTree(RBTree<K,V>& t)
{
    if(t.getRoot() != nullptr)
        printTree(t.getRoot(),0);
    else
        std::cout << "Empty tree" << std::endl;
}

template<typename K,typename V>
void printTree(RBNode<K,V>* t, int level)
{
    if(t != nullptr)
    {
        using namespace std;
        for(int i = 0; i < level; i++)
            cout << "\t";
        cout << t->getColor() << ": " << t->getKey() << endl;
        printTree(t->getLeft(),level + 1);
        printTree(t->getRight(),level + 1);
    }
}
#endif

#endif
