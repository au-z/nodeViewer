#include "tree.h"

int main( int argc, char *argv[] ){

	Node n("Optimus Prime");
	cout << "Address of Optimus: " <<  &n << endl;
	Node m("Bumbleboo", &n);
	cout << "Address of Bumbleboo's parent: " << m.parent << endl;

	Tree tree;
	tree.add2Test(4);
	cout << "Address to be added: " << &n << endl;
	tree.addNode(&n);
	// tree.print();
	// tree.addNode(&m);
	// tree.print();
	// tree.addNode("Rawhide", tree.getIndex("Optimus Prime"));
	// tree.print();
	// tree.delNode(0);
	// tree.print();
	return 0;
}