#include "Tree.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Create and Insert." << endl;
	//Create and Initialize Tree
	Tree tree;
	tree.insert(10);
	tree.insert(7);
	tree.insert(3);
	tree.insert(9);
	tree.insert(15);
	tree.insert(13);
	tree.insert(17);

	//Print
	cout << "Pre-Order: ";
	tree.printPre();
	cout << "In-Order: ";
	tree.printIn();
	cout << "Post-Order: ";
	tree.printPost();

	cout << endl;
	cout << "Remove 9, 7, and 15." << endl;
	//Remove
	tree.remove(9);
	tree.remove(7);
	tree.remove(15);

	//Print
	cout << "Pre-Order: ";
	tree.printPre();
	cout << "In-Order: ";
	tree.printIn();
	cout << "Post-Order: ";
	tree.printPost();

	return 0;
}
