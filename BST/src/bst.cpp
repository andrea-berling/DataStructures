#ifndef BST_CPP
#define BST_CPP
#include "../include/bst.h"

template<typename T>
void RBTree<T>::link(RBTree<T>::Node* p,RBTree<T>::Node* u,const T x)
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
RBTree<T>::RBTree(const T key)
{
    root = new Node();
    root->left = nullptr;
    root->right = nullptr;
    root->parent = nullptr;
    root->color = BLACK;
}

template<typename T>
RBTree<T>::RBTree(const RBTree<T>::Node& u)
{
    root = &u;
}

template<typename T>
RBTree<T>::~RBTree()
{
    if (root != nullptr)
    {
        typename RBTree<T>::Node* old = min();
        typename RBTree<T>::Node* next = successorNode(old);

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
typename RBTree<T>::Node* RBTree<T>::lookupNode(const T x) const
{
    typename RBTree<T>::Node *t = root;
    while(t != nullptr && t->key != x)
        t = x < t->key ? t->left : t->right;
    return t;
}

template<typename T>
void RBTree<T>::insertNode(const RBTree<T>::Node* u)
{
    if(u != nullptr)
       insertNode(u->key);
}

template<typename T>
void RBTree<T>::insertNode(const T x)
{
    typename RBTree<T>::Node *p = nullptr;
    typename RBTree<T>::Node *u = root;
    while(u != nullptr && u->key != x)
    {
        p = u;
        u = x < u->key? u->left : u->right;
    }
    if (u == nullptr || u->key != x)
    {
        typename RBTree<T>::Node* n = new RBTree<T>::Node();
        n->key = x;
        n->left = nullptr;
        n->right = nullptr;
        n->parent = nullptr;
        n->color = BLACK;
        link(p,n,x);
        balanceInsert(n);
        while(n->parent != nullptr)
            n = n->parent;
        root = n;
    }
}

template<typename T>
typename RBTree<T>::Node* RBTree<T>::min() const
{
    if(root == nullptr)
        return root;
    else
    {
        typename RBTree<T>::Node* t = root;
        while(t->left != nullptr)
            t = t->left;
        return t;
    }
}

template<typename T>
typename RBTree<T>::Node* RBTree<T>::max() const
{
    if(root == nullptr)
        return root;
    else
    {
        typename RBTree<T>::Node* t = root;
        while(t->right != nullptr)
            t = t->right;
        return t;
    }
}

template<typename T>
void RBTree<T>::removeNode(T x)
{
    typename RBTree<T>::Node* u = lookupNode(x);
    if(u != nullptr)
    {
        if(u->left != nullptr && u->right != nullptr)
        {
            typename RBTree<T>::Node* s = u->right;
            while(s->left != nullptr)
                s = s->left;
            u->key = s->key;
            x = s->key;
            u = s;
        }

        typename RBTree<T>::Node* t;
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
                    typename RBTree<T>::Node* dummy = new RBTree<T>::Node();
                    dummy->right = nullptr;
                    dummy->left = nullptr;
                    dummy->color = BLACK;
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
typename RBTree<T>::Node* RBTree<T>::successorNode(RBTree<T>::Node* t) const
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
    typename RBTree<T>::Node* p = t->parent;
    while(p != nullptr && t == p->right)
    {
        t = p;
        p = p->parent;
    }

    return p;
}

template<typename T>
typename RBTree<T>::Node* RBTree<T>::predecessorNode(RBTree<T>::Node* t) const
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
    typename RBTree<T>::Node* p = t->parent;
    while(p != nullptr && t == p->left)
    {
        t = p;
        p = p->parent;
    }

    return p;
}

//OLD STUFF

template<typename T>
typename RBTree<T>::Node* RBTree<T>::rotateLeft(RBTree<T>::Node* x) const
{
    typename RBTree<T>::Node* y = x->right;
    typename RBTree<T>::Node* p = x->parent;

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
typename RBTree<T>::Node* RBTree<T>::rotateRight(RBTree<T>::Node* x) const
{
    typename RBTree<T>::Node* y = x->left;
    typename RBTree<T>::Node* p = x->parent;

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
void RBTree<T>::balanceInsert(RBTree<T>::Node* t) const
{
    t->color = RED;

    while (t != nullptr)
    {
        typename RBTree<T>::Node* p = t->parent;
        typename RBTree<T>::Node* n = p != nullptr ? p->parent : nullptr;
        typename RBTree<T>::Node* z = n == nullptr ? nullptr : (n->left == p ? n->right : n->left) ;
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
void RBTree<T>::balanceDelete(RBTree<T>::Node* t) const
{
    while(t != root && t->color == BLACK)
    {
        typename RBTree<T>::Node* p = t->parent;
        if (t == p->left)
        {
            typename RBTree<T>::Node* f = p->right;
            typename RBTree<T>::Node* ns = f == nullptr ? nullptr : f->left;
            typename RBTree<T>::Node* nd = f == nullptr ? nullptr : f->right;
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
            RBTree<T>::Node* f = p->left;
            RBTree<T>::Node* ns = f == nullptr ? nullptr : f->left;
            RBTree<T>::Node* nd = f == nullptr ? nullptr : f->right;
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
typename RBTree<T>::Node* RBTree<T>::getRoot() const
{
    return root;
}

template<typename T>
typename RBTree<T>::iterator RBTree<T>::begin()
{
    typename RBTree<T>::iterator it(*this,min());
    return it;
}
// Returns an typename RBTree<T>::iterator pointing to the first element of the tree

template<typename T>
typename RBTree<T>::iterator RBTree<T>::end()
{
    typename RBTree<T>::iterator it(*this,nullptr);
    return it;
}
// Returns an typename RBTree<T>::iterator pointing to one past the end

template<typename T>
typename RBTree<T>::iterator RBTree<T>::last()
{
    typename RBTree<T>::iterator it(*this,max());
    return it;
}
// Returns an typename RBTree<T>::iterator pointo to the last element

template<typename T>
T& RBTree<T>::iterator::operator*() const
{
    return node->key;
}
// Returns the element pointed by the iterator

template<typename T>
bool RBTree<T>::iterator::operator==(const typename RBTree<T>::iterator rhs) const
{
    return node == rhs.node && baseTree == rhs.baseTree;
}
// Returns true if the node pointed by the lhs iterator is the same as the one pointed by rhs

template<typename T>
bool RBTree<T>::iterator::operator!=(const typename RBTree<T>::iterator rhs) const
{
    return !(*this == rhs);
}
// Returns !(lhs == rhs)

template<typename T>
typename RBTree<T>::iterator& RBTree<T>::iterator::operator++()
{
    if(node != nullptr)
    {
        node = baseTree->successorNode(node);
    }
    return *this;
}
// Increments the RBTree<T>::iterator and returns the new RBTree<T>::iterator (prefix increment)

template<typename T>
typename RBTree<T>::iterator RBTree<T>::iterator::operator++(int)
{
    RBTree<T>::iterator old(*this);
    ++(*this);
    return old;
}
// Increments the RBTree<T>::iterator and returns the RBTree<T>::iterator as it was before the increment (postfix increment)

template<typename T>
typename RBTree<T>::iterator& RBTree<T>::iterator::operator--()
{
    if(node != nullptr)
    {
        node = baseTree->predecessorNode(node);
    }
    return *this;
}
// Decrements the RBTree<T>::iterator and returns the new RBTree<T>::iterator (prefix decrement)

template<typename T>
typename RBTree<T>::iterator RBTree<T>::iterator::operator--(int)
{
    RBTree<T>::iterator old(*this);
    --(*this);
    return old;
}
// Decrements the RBTree<T>::iterator and returns the RBTree<T>::iterator as it was before the increment (postfix decrement)
#endif
