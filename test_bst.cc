#include "BinarySearchTree.h"
#include "BinaryTree.h"

using namespace std;

/********/
/* Main */
/********/

int main(int argc, char *argv[])
{
	// create a new tree from an string input stream using a fixed phrase
	istringstream instr("What fresh hell could this be?");
	BinarySearchTree<string> bst;
	instr >> bst;
	cout << bst << "\n";
	int k[8] = { 1,2,3,4,5,6,7,8 };
	BinarySearchTree<int> intTree;
	intTree.init_from_sorted_array(k, 8);
	PDF *pdf = new PDF("intTree.pdf");
	intTree.display(pdf, "Int Tree");
	pdf->finish();
	delete pdf;
	int l[8] = { 4, 1, 6, 7, 3, 5, 10, 2 };
	intTree.init(l, 8);
	pdf = new PDF("intTree2.pdf");
	intTree.display(pdf, "Int Tree");
	pdf->finish();
	delete pdf;
	int* myInt = intTree.lookup(7);
	cout << "My int = " << *myInt << " should be 7" << endl;
	int my[8] = { 0 };
	int my2[8] = { 1, 2, 3, 5, 6, 7, 10 };
	intTree.to_array(my, 7);
	for (int anInt = 0; anInt < 7; anInt++)
		cout << my[anInt] << " ," << my2[anInt] << endl;
	/* The output should be

	   What be? could fresh hell this

	*/
}