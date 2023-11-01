#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree t;
	string spacer = "----------------------";

	t.insert(10);
	t.insert(4);
	t.insert(12);
	t.insert(6);
	t.insert(11);
	t.insert(1);

	t.printTree();
	t.deleteNode(1);
	cout << endl << spacer;
	t.printTree();
	t.deleteNode(10);
	cout << endl << spacer;
	t.printTree();
	t.treeHeight();
}