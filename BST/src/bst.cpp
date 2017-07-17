#ifndef BST_CPP
#define BST_CPP
#include "../include/bst.h"

template<typename T>
RBNode<T>::RBNode()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}
// Default constructor

template<typename T>
RBNode<T>::RBNode(T key): key(key)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}
// Creates a node given a key

template<typename T>
T RBNode<T>::getKey()
{
    return key;
}
// Key getter

template<typename T>
RBNode<T>* RBNode<T>::getParent()
{
    return parent;
}

template<typename T>
RBNode<T>* RBNode<T>::getLeft()
{
    return left;
}

template<typename T>
RBNode<T>* RBNode<T>::getRight()
{
    return right;
}

template<typename T>
color_t RBNode<T>::getColor()
{
    return color;
}

template<typename T>
void link(RBNode<T>* p,RBNode<T>* u,T x)
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

template<typename T>
RBTree<T>::RBTree()
{
    root = nullptr;
}

template<typename T>
RBTree<T>::RBTree(T key)
{
    root = new RBNode<T>(key);
}

template<typename T>
RBTree<T>::RBTree(RBNode<T>& u)
{
    root = &u;
}

template<typename T>
RBTree<T>::~RBTree()
{
    if (root != nullptr)
    {
        RBNode<T>* old = min();
        RBNode<T>* next = successorNode(old);

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

template<typename T>
RBNode<T>* RBTree<T>::lookupNode(T x)
{
    RBNode<T> *t = root;
    while(t != nullptr && t->key != x)
        t = x < t->key ? t->left : t->right;
    return t;
}

template<typename T>
void RBTree<T>::insertNode(RBNode<T>* u)
{
    if(u != nullptr)
       insertNode(u->key);
}

template<typename T>
void RBTree<T>::insertNode(T x)
{
    RBNode<T> *p = nullptr;
    RBNode<T> *u = root;
    while(u != nullptr && u->key != x)
    {
        p = u;
        u = x < u->key? u->left : u->right;
    }
    if (u == nullptr || u->key != x)
    {
        RBNode<T>* n = new RBNode<T>(x);
        link(p,n,x);
        balanceInsert(n);
        while(n->parent != nullptr)
            n = n->parent;
        root = n;
    }
}

template<typename T>
RBNode<T>* RBTree<T>::min()
{
    if(root == nullptr)
        return root;
    else
    {
        RBNode<T>* t = root;
        while(t->left != nullptr)
            t = t->left;
        return t;
    }
}

template<typename T>
RBNode<T>* RBTree<T>::max()
{
    if(root == nullptr)
        return root;
    else
    {
        RBNode<T>* t = root;
        while(t->right != nullptr)
            t = t->right;
        return t;
    }
}

template<typename T>
void RBTree<T>::removeNode(T x)
{
    RBNode<T>* u = lookupNode(x);
    if(u != nullptr)
    {
        if(u->left != nullptr && u->right != nullptr)
        {
            RBNode<T>* s = u->right;
            while(s->left != nullptr)
                s = s->left;
            u->key = s->key;
            x = s->key;
            u = s;
        }

        RBNode<T>* t;
        if(u->left != nullptr && u->right == nullptr)
            t = u->left;
        else
            t = u->right;
        if(u->parent != nullptr && u->parent->key == x) // particular case i handle "manually"
        {
            if(t != nullptr)
                t->parent = u->parent;
            if(u == u->parent->left)
                u->parent->left = t;
            else 
                u->parent->right = t;
        }
        else
            link(u->parent,t,x);

        if(u->parent != nullptr)
        {
            if(u->color == BLACK)
            {
                if(t != nullptr)
                    balanceDelete(t);
                else
                {
                    RBNode<T>* dummy = new RBNode<T>();
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
        }
        else
        {
            root = nullptr;
        }

        delete u;

    }
    while(root != nullptr && root->parent != nullptr) // if the balanceDelete procedure modifes the root, it has to be restored
        root = root->parent;
}

template<typename T>
RBNode<T>* RBTree<T>::successorNode(RBNode<T>* t)
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
    RBNode<T>* p = t->parent;
    while(p != nullptr && t == p->right)
    {
        t = p;
        p = p->parent;
    }

    return p;
}

template<typename T>
RBNode<T>* RBTree<T>::predecessorNode(RBNode<T>* t)
{
    if(t == nullptr)
        return t; 
    if(t->left != nullptr)
    {
        t = t->left;            //searche the max of the left subtree
        while(t->right != nullptr)
            t = t->right;
        return t;
    }
    RBNode<T>* p = t->parent;
    while(p != nullptr && t == p->left)
    {
        t = p;
        p = p->parent;
    }

    return p;
}

//OLD STUFF

template<typename T>
RBNode<T>* RBTree<T>::rotateLeft(RBNode<T>* x)
{
    RBNode<T>* y = x->right;
    RBNode<T>* p = x->parent;

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

template<typename T>
RBNode<T>* RBTree<T>::rotateRight(RBNode<T>* x)
{
    RBNode<T>* y = x->left;
    RBNode<T>* p = x->parent;

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

template<typename T>
void RBTree<T>::balanceInsert(RBNode<T>* t)
{
    t->color = RED;

    while (t != nullptr)
    {
        RBNode<T>* p = t->parent;
        RBNode<T>* n = p != nullptr ? p->parent : nullptr;
        RBNode<T>* z = n == nullptr ? nullptr : (n->left == p ? n->right : n->left) ;
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

template<typename T>
void RBTree<T>::balanceDelete(RBNode<T>* t)
{
    while(t != root && t->color == BLACK)
    {
        RBNode<T>* p = t->parent;
        if (t == p->left)
        {
            RBNode<T>* f = p->right;
            RBNode<T>* ns = f == nullptr ? nullptr : f->left;
            RBNode<T>* nd = f == nullptr ? nullptr : f->right;
            if (f != nullptr && f->color == RED)
            {
                p->color = RED;
                f->color = BLACK;
                rotateLeft(p);
            }
            else
            {
                if((ns == nullptr || ns->color == BLACK) && (nd == nullptr || nd->color == BLACK))
                {
                    if(f != nullptr)
                        f->color = RED;
                    t = p;
                }
                else if ((ns != nullptr && ns->color == RED) && (nd == nullptr || nd->color == BLACK))
                {
                    ns->color = BLACK;
                    f->color = RED;
                    rotateRight(f);
                }
                else if (nd != nullptr && nd->color == RED)
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
            RBNode<T>* f = p->left;
            RBNode<T>* ns = f == nullptr ? nullptr : f->left;
            RBNode<T>* nd = f == nullptr ? nullptr : f->right;
            if (f != nullptr && f->color == RED)
            {
                p->color = RED;
                f->color = BLACK;
                rotateRight(p);
            }
            else
            {
                if((ns == nullptr || ns->color == BLACK) && (nd == nullptr || nd->color == BLACK))
                {
                    if(f != nullptr)
                        f->color = RED;
                    t = p;
                }
                else if ((nd != nullptr && nd->color == RED) && (ns == nullptr || ns->color == BLACK))
                {
                    nd->color = BLACK;
                    f->color = RED;
                    rotateLeft(f);
                }
                else if (ns != nullptr && ns->color == RED)
                {
                    f->color = p->color;
                    p->color = BLACK;
                    ns->color = BLACK;
                    rotateRight(p);
                    t = root;
                }
            }
        }
    }
    if (t != nullptr)
        t->color = BLACK;
}

template<typename T>
RBNode<T>* RBTree<T>::getRoot()
{
    return root;
}

#endif
