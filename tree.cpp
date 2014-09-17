#include "tree.h"

bool debug = false;

Tree::Tree() : nodes() {
	name = "Unnamed Tree";
	depth = 0;
}

Tree::Tree(string n, bool sD){
	strictDepth = sD;
	name = n;
	depth = 0;
}

short Tree::calcDepth(unsigned i){
	if(nodes[i].root){
		return 0;
	}else{
		if(debug) cout << "calc depth...";
		short d = 0;
		while(!nodes[i].root){
			++d;
			i = nodes[i].parent;
		}
		if(debug) cout << d << endl;
		return d;
	}
}

//will become useless as these get larger
void Tree::print(bool verbose){
	string str = "[ ";
	for(int i=0; i<nodes.size(); i++){
		string displayParent;
		if(nodes[i].parent == -1){ 
			displayParent = "Root";
		}else{
			displayParent = nodes[nodes[i].parent].name;
		}
		str += "{" + nodes[i].name + ":" + displayParent;
		if(verbose){
			std::stringstream ss;
			ss << nodes[i].depth;
			string strDepth = ss.str();
			str += ":" + strDepth;
		}
		str += "}";
		if(i!=nodes.size()-1){
			str += " , ";
		}
	}
	str += " ]";
	cout << str << endl;
}

unsigned Tree::getSize(){ return (unsigned) nodes.size(); }

short Tree::getDepth(){ return depth; }

int Tree::getIndex(string n){
	for (int i = 0; i < nodes.size(); ++i){
		if(nodes[i].name.compare(n) == 0){
			return i;
		}
	}
	return -1;
}

Node Tree::getNode(unsigned i){ return nodes[i]; }

void Tree::addNode(Node &n){ 
	nodes.push_back(n); 
	nodes[nodes.size()-1].depth = calcDepth(nodes.size()-1); 
}

void Tree::addNode(string n = "Unnamed", int parentIndex = -1){
	Node node(n, parentIndex);
	nodes.push_back(node);
	nodes[nodes.size()-1].depth = calcDepth(nodes.size()-1);
}

void Tree::editNode(unsigned i, string n, short d, int p = -1){
	nodes[i].name = n;
	if(strictDepth){
		nodes[i].depth = calcDepth(i);
	}else{
		nodes[i].depth = d;
	}
	if(p >= 0) nodes[i].parent = p;
	else nodes[i].parent = -1;
}

void Tree::delNode(unsigned i){
	nodes.erase(nodes.begin()+i);
}



