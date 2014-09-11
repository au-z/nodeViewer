#include "tree.h"
using namespace std;

Tree::Tree(){
	name = "Unnamed Tree";
}

Tree::Tree(string n, vector<Node> import){
	name = n;
	nodes = import;
}

unsigned Tree::getSize(){
	return (unsigned) nodes.size();
}

short Tree::getDepth(){
	return depth;
}

string Tree::toString(){
	string str = "[ ";
	for(int i=nodes.size()-1; i>=0; i--){
		str += nodes[i].toString(false);
		if(i!=0){
			str += " , ";
		}
	}
	str += " ]";
	return str;
}

void Tree::addNode(Node n){
	nodes.push_back(n);
	n.setTreeIndex(nodes.size()-1);
}

void Tree::delNode(unsigned i){
	nodes.erase(nodes.begin()+i);
}

void Tree::editNode(unsigned i, string n = "undefined", bool r = 0, Node *p = 0){
	if(n != "undefined") nodes[i].setName(n);
	if(r != 0) nodes[i].setRoot(r);
	if(p != 0) nodes[i].setParent(p);
}