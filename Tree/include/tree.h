#ifndef TREE_H
#define TREE_H

template<typename T> class TreeNode;

template<typename T>
class Tree
{
	private:

        TreeNode<T>* root;

	public:

		Tree();
		// Constructs an empty tree
		
		Tree(T v);
		// Constructs a tree with a single node containing v
		
        ~Tree();
        // Destructor

        TreeNode<T>* getRoot();
        // getter for the root
};

template<typename T>
class TreeNode
{
    private:

        friend class Tree<T>;
        TreeNode *parent,*child,*sibling;
        T value;
		template<typename U>
		friend void deleteTree(Tree<U>* t);

    public:

        TreeNode();
        // Default constructor

        TreeNode(T value);
        // Creates a node given a value

        T getValue();
        // Value getter

        TreeNode* getParent();
        // Getter for the parent of the node

        TreeNode* getChild();
        // Getter for the left child of the node

        TreeNode* getSibling();
        // Getter for the right child of the node

		void insertChild(TreeNode* t);
		// Inserts t subtree as the leftmost child of the current node
		// Precondition: t->parent == nullptr 

		void insertSibling(TreeNode* t);
		// Inserts t subtree as the next sibling of the current node
		// Precondition: t->parent == nullptr 

		void deleteChild();
		// Deletes the subtree that is the leftmost child of the current node

		void deleteSibling();
		// Deletes the subtree that is the next sibling of the current node


};

#include "../src/tree.cpp"

#endif
