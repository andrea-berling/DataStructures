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

        struct Node
        {
                T key;
                Node *parent,*left,*right;
                color_t color;
        };

        class iterator
        {
            private:

                RBTree<T>* baseTree;
                Node* node;

            public:

                iterator(RBTree<T>& tree,RBTree<T>::Node* node): baseTree(&tree),node(node) {}
                // Creates a new List_iterator given a node

                iterator(): node(nullptr) {}
                // Default constructor

                iterator(const iterator& it)
                {
                    this->baseTree = it.baseTree;
                    this->node = it.node;
                }
                // Copy constructor

                T& operator*() const;
                // Returns the element pointed by the iterator

                bool operator==(const iterator rhs) const;
                // Returns true if the node pointed by the lhs iterator is the same as the one pointed by rhs

                bool operator!=(const iterator rhs) const;
                // Returns !(lhs == rhs)

                iterator& operator++();
                // Increments the iterator and returns the new iterator (prefix increment)

                iterator operator++(int);
                // Increments the iterator and returns the iterator as it was before the increment (postfix increment)

                iterator& operator--();
                // Decrements the iterator and returns the new iterator (prefix decrement)

                iterator operator--(int);
                // Decrements the iterator and returns the iterator as it was before the increment (postfix decrement)
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
        
        iterator begin();
        // Returns an iterator pointing to the first element of the tree

        iterator end();
        // Returns an iterator pointing to one past the end

        iterator last();
        // Returns an iterator pointo to the last element

    private:

        Node* root;

};

#include "../src/bst.cpp"
#endif
