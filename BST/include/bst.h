/**
 * Implementation of a Binary Search Tree. Specifically a Red-Black tree
 */
#ifndef RBTree_H
#define RBTree_H
#define DEBUG

enum color_t { RED, BLACK};

template<typename K,typename V> class RBNode;
template<typename K, typename V> class RBTree;

template<typename K, typename V> void link(RBNode<K,V>* p,RBNode<K,V>* u,K x);

template<typename K,typename V>
class RBNode
{
    private:

        friend class RBTree<K,V>;
        K key;
        V value;
        RBNode *parent,*left,*right;
        color_t color;

    public:

        RBNode();
        // Default constructor

        RBNode(K key);
        // Creates a node given a key
        
        RBNode(K key,V value);
        // Creates a node given a key

        K getKey();
        // Key getter

        V getValue();
        // Value getter

        RBNode* getParent();
        RBNode* getLeft();
        RBNode* getRight();
        
        color_t getColor();
        // void operator=(RBNode& rhs);
        // overload of assignement operator

        friend void link<>(RBNode* p,RBNode* u,K x);

};

template<typename K, typename V>
class RBTree
{
    private:

        RBNode<K,V>* root;

    public:

        RBTree();
        // Default constructor

        RBTree(K key);
        // Creates a new tree given a key
        
        RBTree(K key,V value);
        // Creates a new tree given a key-value pair
        
        RBTree(RBNode<K,V>& u);
        // Creates a new tree given an existing node
        
        ~RBTree();
        // Destructor

        RBNode<K,V>* lookupNode(K x);
        // Given a key x, it returns the corresponding node, if present; if not, nil

        void insertNode(RBNode<K,V>* u);
        // It inserts the given node into the tree; it returns a pointer to the root of the new tree

        void insertNode(K x, V v);
        // It inserts the x-v key-value pair into the tree; it returns a pointer to the root of the new tree

        RBNode<K,V>* min();
        // It returns a pointer to the node with the "smallest" key
        
        RBNode<K,V>* max();
        // It returns a pointer to the node with the "biggest" key
        
        void removeNode(K x);
        // It removes the x key-value pair in the tree; it returns a pointer to the root of the new tree

        RBNode<K,V>* successorNode(RBNode<K,V>* t);
        // It returns a pointer to the successor node

        RBNode<K,V>* predecessorNode(RBNode<K,V>* t);
        // It returns a pointer to the predecessor node

        RBNode<K,V>* rotateLeft(RBNode<K,V>* x);
        // It makes a rotation to the left starting from x

        RBNode<K,V>* rotateRight(RBNode<K,V>* x);
        // It makes a rotation to the right starting from x

        void balanceInsert(RBNode<K,V>* t);

        void balanceDelete(RBNode<K,V>* t);

        RBNode<K,V>* getRoot();

};

#ifdef DEBUG

template<typename K,typename V>
void printTree(RBTree<K,V>& t);
template<typename K,typename V>
void printTree(RBNode<K,V>* t, int level);

#endif

#include "../src/bst.cpp"
#endif
