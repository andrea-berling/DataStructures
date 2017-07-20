/**
 * Implementation of a Binary Search Tree. Specifically a Red-Black tree
 */
#ifndef RBTree_H
#define RBTree_H

enum color_t { RED, BLACK};

template<typename T> class RBNode;
template<typename T> class RBTree;

template<typename T> void link(RBNode<T>* p,RBNode<T>* u,T x);

template<typename T>
class RBNode
{
    private:

        friend class RBTree<T>;
        T key;
        RBNode *parent,*left,*right;
        color_t color;

    public:

        RBNode();
        // Default constructor

        RBNode(const T key);
        // Creates a node given a key
        
        T getKey() const;
        // Key getter

        RBNode* getParent() const;
        // Getter for the parent of the node
        
        RBNode* getLeft() const;
        // Getter for the left child of the node

        RBNode* getRight() const;
        // Getter for the right child of the node
        
        color_t getColor() const;
        // Getter for the color of the node

        friend void link<>(RBNode* p,RBNode* u,const T x);
        // auxiliary procedure to link two nodes
};

template<typename T>
class RBTree
{
    private:

        RBNode<T>* root;

    public:

        RBTree();
        // Default constructor

        RBTree(const T key);
        // Creates a new tree given a key
        
        RBTree(const RBNode<T>& u);
        // Creates a new tree given an existing node
        
        ~RBTree();
        // Destructor

        RBNode<T>* lookupNode(const T x) const;
        // Given a key x, it returns the corresponding node, if present; if not, nil

        void insertNode(const RBNode<T>* u);
        // It inserts the given node into the tree; it returns a pointer to the root of the new tree

        void insertNode(const T x);
        // It inserts the x-v key-value pair into the tree; it returns a pointer to the root of the new tree

        RBNode<T>* min() const;
        // It returns a pointer to the node with the "smallest" key
        
        RBNode<T>* max() const;
        // It returns a pointer to the node with the "biggest" key
        
        void removeNode(T x);
        // It removes the x key-value pair in the tree; it returns a pointer to the root of the new tree

        RBNode<T>* successorNode(RBNode<T>* t) const;
        // It returns a pointer to the successor node

        RBNode<T>* predecessorNode(RBNode<T>* t) const;
        // It returns a pointer to the predecessor node

        RBNode<T>* rotateLeft(RBNode<T>* x) const;
        // It makes a rotation to the left starting from x

        RBNode<T>* rotateRight(RBNode<T>* x) const;
        // It makes a rotation to the right starting from x

        void balanceInsert(RBNode<T>* t) const;
        // auxiliary procedure used to balance the tree after insertion of node t

        void balanceDelete(RBNode<T>* t) const;
        // auxiliary procedure used to balance the tree after the removing of a node

        RBNode<T>* getRoot() const;
        // Getter for the root of the tree

};

#include "../src/bst.cpp"
#endif
