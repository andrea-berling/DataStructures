#ifndef TREE_H
#define TREE_H

template<typename T>
class Tree
{
	public:

        class Node
        {
            private:

                Node *parent,*child,*sibling;
                T value;

            public:

                Node():parent(nullptr),child(nullptr),sibling(nullptr),value(T()){}
                // Default constructor

                Node(const T value):parent(nullptr),child(nullptr),sibling(nullptr),value(value){}
                // Creates a node given a value

                T& getValue();
                // Value getter

                void setValue(const T value);
                // Value getter

                Node* getParent() const;
                // Getter for the parent of the node

                Node* getChild() const;
                // Getter for the left child of the node

                Node* getSibling() const;
                // Getter for the right child of the node

                void insertChild(Node* t);
                // Inserts t subtree as the leftmost child of the current node
                // Precondition: t->parent == nullptr 

                void insertSibling(Node* t);
                // Inserts t subtree as the next sibling of the current node
                // Precondition: t->parent == nullptr 

                void deleteChild();
                // Deletes the subtree that is the leftmost child of the current node

                void deleteSibling();
                // Deletes the subtree that is the next sibling of the current node


        };

		Tree();
		// Constructs an empty tree
		
		// Tree(const Tree& t);
        // Copy constructor

		Tree(const T v);
		// Constructs a tree with a single node containing v
		
        ~Tree();
        // Destructor

        Node* getRoot() const; 
        // getter for the root

        void deleteTree(Node* t);
        // Deletes the sub tree with root t

	private:

        Node* root;

};

#include "../src/tree.cpp"

#endif
