#include "tree.h"
using namespace std;

int main( int argc, char *argv[] ){
	bool v = true;

	Node n("N0");
	Node m("N1", 0);

	Tree tree;
	tree.addNode(n);
	tree.print(v);
	tree.addNode(m);
	tree.print(v);
	tree.addNode("N2", tree.getIndex("N0"));
	tree.print(v);
	tree.delNode(0);
	tree.print(v);
	tree.addNode("N0");
	tree.print(v);
	tree.editNode(0,NOCHANGE,-1,tree.getIndex("N0"));
	return 0;
}