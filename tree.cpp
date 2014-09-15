#include "tree.h"

bool debug = true;

Tree::Tree() : nodes() {
	name = "Unnamed Tree";
	depth = 0;
}

//copy constructor from:
// http://stackoverflow.com/questions/13547299/explain-how-vector-of-pointers-can-be-initialized-and-deleted-properly
Tree::Tree(const nodeVec &n) : nodes() {
	nodeVec::const_iterator it(nodes.begin());
	for( ; it != nodes.end() ; ++it){
		nodes.push_back(new Node(**it));
	}
}

// Tree::Tree(string n, nodeVec import){
// 	name = n;
// 	nodes = import;
// }

unsigned Tree::getSize(){
	return (unsigned) nodes.size();
}

short Tree::getDepth(){
	return depth;
}

void Tree::print(){
	string str = "[ ";
	for(int i=0; i<nodes.size(); i++){
		string parent;
		if(nodes[i]->parent == NULL) parent = "Root";
		else parent = nodes[i]->parent->name;
		str += "{ " + nodes[i]->name + " , Parent: " + parent + " }";
		if(i!=nodes.size()-1){
			str += " : ";
		}
	}
	str += " ]";
	cout << str << endl;
}

//gets index position by name by searching through the list
int Tree::getIndex(string n){
	for (int i = 0; i < nodes.size(); ++i){
		if(nodes[i]->name.compare(n) == 0){
			return i;
		}	
	}
	if(debug) cout << "Error: name not found" << endl;
	return -1;	
}

Node Tree::getNode(unsigned i){
	return *nodes[i];
}

void Tree::addNode(string n = "Unnamed", int parentIndex = -1){
	Node node(n);
	if(parentIndex != -1){
		node.parent = nodes[parentIndex];	
	}else 
		node.parent = NULL;
	// cout << "Pushing back: " << &node << endl;
	// cout << "Parent: " << node.parent << endl;
	// nodes.push_back(&node);
}

void Tree::addNode(Node* n){
	nodes.push_back(n);
}

void Tree::add2Test(int i){
	testVec.push_back(i);
}

void Tree::delNode(unsigned i){
	delete &nodes[i];
	nodes.erase(nodes.begin()+i);
}

void Tree::editNode(unsigned i, string n = "undefined", Node *p = 0){
	if(n != "undefined") nodes[i]->name = n;
	if(p != 0) nodes[i]->parent = p;
	if(p != NULL) nodes[i]->root = false;
	else nodes[i]->root = true;
}

// http://stackoverflow.com/questions/13547299/explain-how-vector-of-pointers-can-be-initialized-and-deleted-properly
Tree::~Tree(){
	nodeVec::iterator it;
	for(it=nodes.begin(); it != nodes.end(); ++it){
		delete *it;
		*it = NULL;
	}
}