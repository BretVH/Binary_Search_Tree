using namespace std;

/****************************************************************************/
/***                    Implementation of BinarySearchTree			  ***/
/****************************************************************************/


/****************/
/* Construction */
/****************/

template<class T>
BinarySearchTree<T>::BinarySearchTree(T *elements, int n_elements)
// Constructs this tree to have elements 'elements[1]', 'elements[2]' ...
// as a Binary Search Tree; 'element[0]' is ignored,
// so the total number of cells if 'elements' is 'n_elements + 1'
{
	BinaryTree<T>::root = NULL;
	for (int n = 1; n < n_elements; n++)
		insert(elements[n]);
}



template<class T>
void BinarySearchTree<T>::init(T* elements, int n_elements)
{
	//empty's tree then constructs tree by inserting the elements in T
	//in the order they are held in T
	empty_this();
	BinaryTree<T>::root = NULL;
	for (int n = 1; n < n_elements; n++)
		insert(elements[n]);
}

/**************************/
/*		Mutators    */
/**************************/

template<class T>
bool BinarySearchTree<T>::insert(const T& elem)
//Inserts a node into the tree so as to keep 
//the tree's binary tree property
{
	if (BinaryTree<T>::root == NULL)
	{
		BinaryTree<T>::root = new BTNode<T>(elem);
		return true;
	}
	return insert(BinaryTree<T>::root, elem);
}

template<class T>
bool BinarySearchTree<T>::insert(BTNode<T>*& thisRoot, const T data)
//Insert helper function
{
	if (thisRoot == NULL)
	{
		thisRoot = new BTNode<T>(data);
		return true;
	}
	else if (data < thisRoot->elem)
	{
		return insert(thisRoot->left, data);
	}
	else if (data > thisRoot->elem)
	{
		return insert(thisRoot->right, data);
	}
	else
	{
		return false;
	}
}



/********************/
/* Access and Tests */
/********************/


template<class T>
template<class K> T* BinarySearchTree<T>::lookup(const K& key) const
//Given Key K this method returns the node in the tree containing K
{
	return lookup(key, BinaryTree<T>::root);
}

template<class T>
template<class K> T* BinarySearchTree<T>::lookup(const K& key, BTNode<T>* node) const
{
	//Helper function for lookup
	if (node == NULL)
	{
		// empty.
		return NULL;
	}
	else if (key == node->elem)
	{
		int* inty = &node->elem;
		return inty;
	}
	else if (key < node->elem)
	{
		return lookup(key, node->left);
	}
	else
	{
		return lookup(key, node->right);
	}
}

/************************/
/* Conversion to Arrays */
/************************/

template<class T>
void BinarySearchTree<T>::init_from_sorted_array(T* elements, int n_elements)
{
	//Attempts to create a balanced tree from a sorted array by inserting items
	//using the mid point of an array or sub-array
	empty_this();
	BinaryTree<T>::root = NULL;
	init_from_sorted_array(elements, 0, n_elements);
}

template<class T>
void BinarySearchTree<T>::init_from_sorted_array(T* elements, int start, int end)
{
	//Helper function for init_from_sorted_array
	if (start < end)
	{
		int mid = (start + end) / 2;
		insert(elements[mid]);
		init_from_sorted_array(elements, start, mid);
		init_from_sorted_array(elements, mid + 1, end);
	}
}

template<class T>
int BinarySearchTree<T>::to_array(T* elements, int max)
{
	//returns the elements of this tree into an array using 
	//an inorder traversal, the array should be sorted.
	return to_array(elements, max, BinaryTree<T>::root);
}

template<class T>
int BinarySearchTree<T>::to_array(T* elements, int max, BTNode<T>* thisRoot)
//helper function for to_array
{
	static int pos = 0;
	if (thisRoot == NULL || pos > max)
	{
		return 0;
	}
	to_array(elements, max, thisRoot->left);
	elements[pos++] = thisRoot->elem;
	to_array(elements, max, thisRoot->right);
	return pos;
}

/********************/
/*     I/O          */
/********************/
template<class S>
istream& operator >> (istream& in, BinarySearchTree<S>& obj)
//Inputs data from istream into the binary tree passed as an
//argument to the function.
{
	do
	{
		S elem;
		in >> elem;
		if (!in.fail())
			obj.insert(elem);
	} while (!in.fail());
	return in;
}

template<class T>
ostream& operator<<(ostream& out, BinarySearchTree<T>& obj)
//prints the tree Nodes to the console using an inorder 
//traversal
{
	BTNode<T>* pass = obj.root;
	return inorderPrint(out, pass);
}

template<class T>
ostream& inorderPrint(ostream& out, BTNode<T>* node)
//does an inorder traversal and prints out the elem
{
	if (!node)
		return out;
	inorderPrint(out, node->left);
	out << node->elem << " ";
	inorderPrint(out, node->right);
	return out;
}
