#include "node.h"
using namespace std;

Node::Node(){
	name = "Named Node";
	root = true;
	parent = NULL;
	treeIndex = (unsigned) NULL;
}

Node::Node(string n, bool r, Node *p){
	name = n;
	root = r;
	parent = p;
	treeIndex = (unsigned) NULL;
}

string Node::toString(bool all){
	string result = "{" + name + " , Root: ";
	if(root){result += "true";}else{result += "false";}
	result += " , ";
	result += "Parent: ";
	if(all){
		if(root == true) result += "NULL";
		else result += parent->toString(true);
	}else{
		if(root == true) result += "NULL";
		else result += "___";
	}
	result += "}";
	return result;
	cout << &parent << endl;
}

void Node::setParent(Node *p){
	parent = p;
	if (parent == NULL) root = true;
	else root = false;
}

void Node::setName(string n){name = n;}

void Node::setRoot(bool r){root = r; if(root) parent = NULL;}

void Node::setTreeIndex(unsigned i){treeIndex = i;}

Node* Node::getParent(){return parent;}

string Node::getName(){return name;}

bool Node::getRoot(){return root;}

unsigned Node::getTreeIndex(){return treeIndex;}
