#ifndef TREE_H
#define TREE_H

template<typename T>
class Tree
{
	private:

		T value;
		Tree *Parent,*Child,*Sibling;
		template<typename U>
		friend void deleteTree(Tree<U>* t);

	public:

		Tree();
		// Constructs an empty tree
		
		Tree(T v);
		// Constructs a tree with a single node containing v
		
		T read();
		// Retunrns the value of the current node
		
		Tree* parent();
		// Returns the parent; nullptr if absent

		Tree* leftmostChild();
		// Returns the leftmost child

		Tree* rightSibling();
		// Returns the next sibling

		void insertChild(Tree* t);
		// Inserts t subtree as the leftmost child of the current node
		// Precondition: t->parent == nullptr 

		void insertSibling(Tree* t);
		// Inserts t subtree as the next sibling of the current node
		// Precondition: t->parent == nullptr 

		void deleteChild();
		// Deletes the subtree that is the leftmost child of the current node

		void deleteSibling();
		// Deletes the subtree that is the next sibling of the current node

        void destroy();
        // Frees the memory occupied by the tree
};

#include "../src/tree.cpp"

#endif
