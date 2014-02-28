#include "BinaryTree.h"
#include "BinarySearchTree.h"


using namespace std;

/********/
/* Main */
/********/

int main( int argc, char *argv[] )
{
  BinarySearchTree<string> bst;

  // initialize 'bst' from the standard input
  cin >> bst;

  // write it as a PDF file
  PDF *pdf = new PDF("bst.pdf");
  bst.display(pdf, "My binary Tree");
  pdf->finish();
  delete pdf;
  cout << bst << endl;
  // create a new tree from an string input stream using a fixed phrase
  istringstream instr("What fresh hell could this be?");
  BinarySearchTree<string> bst2;
  instr >> bst2;
  cout << bst2 << "\n";
  int k[8] = {1,2,3,4,5,6,7,8};
  BinarySearchTree<int> intTree;
  intTree.init_from_sorted_array(k, 8);
  pdf = new PDF("intTree.pdf");
  intTree.display(pdf, "Int Tree");
  pdf->finish();
  delete pdf;
  int l[8] = {4, 1, 6, 7, 3, 5, 10, 2};
  intTree.init(l, 8);
  pdf = new PDF("intTree2.pdf");
  intTree.display(pdf, "Int Tree");
  pdf->finish();
  delete pdf;
  int* myInt = intTree.lookup( 7 );
  cout << "My int = " << *myInt << " should be 7" << endl;
  int my[8] = {0};
  int my2[8] = {1, 2, 3, 5, 6, 7, 10}; 
  intTree.to_array(my, 7);
  bool ak;
  for( int anInt = 0; anInt < 7; anInt++ )
       cout << my[anInt] << " ," << my2[anInt] << endl;
  /* The output should be
     
     What be? could fresh hell this

  */
}