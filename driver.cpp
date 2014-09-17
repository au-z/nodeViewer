#include "tree.h"
using namespace std;

int main( int argc, char *argv[] ){

	Node n("N0");
	Node m("N1", 0);

	Tree tree;
	tree.addNode(n);
	tree.print(true);
	tree.addNode(m);
	tree.print(true);
	tree.addNode("N2", tree.getIndex("N0"));
	tree.print(true);
	return 0;
}