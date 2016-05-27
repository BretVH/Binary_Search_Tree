#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

using namespace std;

template <class T>
class BinarySearchTree : public BinaryTree<T> {
public:
	BinarySearchTree() { this->root = NULL; }
	BinarySearchTree(const BinarySearchTree *src) : BinaryTree<T>(src) {}
	BinarySearchTree(T *elements, int n_elements);


	/* BST Operations */
	bool insert(const T& elem);
	bool insert(BTNode<T>*& node, const T);
	template<class K> T* lookup(const K& key) const;
	template<class K> T* lookup(const K& key, BTNode<T>* node) const;
	bool empty_this() { empty(BinaryTree<T>::root); BinaryTree<T>::root = NULL; return true; }


	/* Other Operations */
	void init_from_sorted_array(T *elements, int n_elements);
	int to_array(T *elements, int max);
	int to_array(T* elements, int max, BTNode<T>* thisRoot);
	void init(T* elements, int n_elements);
	void init_from_sorted_array(T* elements, int start, int end);

	/* Input/Output Operators */
	template<class S>
	friend istream& operator >> (istream& in, BinarySearchTree<S>& obj);

	template<class S>
	friend ostream& operator<<(ostream& in, BinarySearchTree<S>& obj);

	template<class S>
	friend ostream& inorderPrint(ostream& out, BTNode<S>* node);

protected:
	// helper functions
	//BTNode<T>* root;
};

#include "BinarySearchTree.cpp"

#endif
