/**
 * Implementation of a Binary Search Tree. Specifically a Red-Black tree
 */
#ifndef RBTree_H
#define RBTree_H

enum color_t { RED, BLACK};

template<typename T>
class RBTree
{
    public:

            class Node
            {
                private:

                    friend class RBTree<T>;
                    T key;
                    Node *parent,*left,*right;
                    color_t color;

                public:

                    Node(): key(T()),parent(nullptr),left(nullptr),right(nullptr),color(BLACK) {}
                    // Default constructor

                    Node(const T key): key(key),parent(nullptr),left(nullptr),right(nullptr),color(BLACK) {}
                    // Creates a node given a key

                    T getKey() const;
                    // Key getter

                    Node* getParent() const;
                    // Getter for the parent of the node

                    Node* getLeft() const;
                    // Getter for the left child of the node

                    Node* getRight() const;
                    // Getter for the right child of the node

                    color_t getColor() const;
                    // Getter for the color of the node

            };

        RBTree();
        // Default constructor

        RBTree(const T key);
        // Creates a new tree given a key
        
        RBTree(const Node& u);
        // Creates a new tree given an existing node
        
        ~RBTree();
        // Destructor

        Node* lookupNode(const T x) const;
        // Given a key x, it returns the corresponding node, if present; if not, nil

        void insertNode(const Node* u);
        // It inserts the given node into the tree; it returns a pointer to the root of the new tree

        void insertNode(const T x);
        // It inserts the x-v key-value pair into the tree; it returns a pointer to the root of the new tree

        Node* min() const;
        // It returns a pointer to the node with the "smallest" key
        
        Node* max() const;
        // It returns a pointer to the node with the "biggest" key
        
        void removeNode(T x);
        // It removes the x key-value pair in the tree; it returns a pointer to the root of the new tree

        Node* successorNode(Node* t) const;
        // It returns a pointer to the successor node

        Node* predecessorNode(Node* t) const;
        // It returns a pointer to the predecessor node

        Node* rotateLeft(Node* x) const;
        // It makes a rotation to the left starting from x

        Node* rotateRight(Node* x) const;
        // It makes a rotation to the right starting from x

        void balanceInsert(Node* t) const;
        // auxiliary procedure used to balance the tree after insertion of node t

        void balanceDelete(Node* t) const;
        // auxiliary procedure used to balance the tree after the removing of a node

        Node* getRoot() const;
        // Getter for the root of the tree

        void link(Node* p,Node* u,const T x);
        // auxiliary procedure to link two nodes

    private:

        Node* root;

};

#include "../src/bst.cpp"
#endif
