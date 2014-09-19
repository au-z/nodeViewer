#include "tree.h"
#include "sstream.h"

bool debug = true;

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
		short d = 0;
		while(!nodes[i].root){
			++d;
			i = nodes[i].parent;
		}

		return d;
	}
}

//will become useless as these get larger
void Tree::print(bool verbose){
	string str;
	if(verbose){
		str = name + " strict: ";
		if(strictDepth){ str += "T "; }
		else{ str += "F "; }
		cout << str << endl; 
	}
	str = ""; //empty the string for the new line
	str += "[ ";
	for(int i=0; i<nodes.size(); i++){
		string displayParent;
		if(nodes[i].parent == -1){ 
			displayParent = ROOT;
		}else{
			displayParent = nodes[nodes[i].parent].name;
		}
		str += "{" + nodes[i].name + ":" + displayParent;
		if(verbose){
			stringstream ss;
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
	cout << endl;
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
	if((n.parent < -1 || n.parent >= nodes.size()) && nodes.size() != 0){
		cout << "Error adding node: parent does not exist..." << endl;
	}else{
		nodes.push_back(n); 
		nodes[nodes.size()-1].depth = calcDepth(nodes.size()-1); 
	}
}

void Tree::addNode(string n = "Unnamed", int parentIndex = -1){
	if((parentIndex <= -2 || parentIndex >= nodes.size()) && nodes.size() != 0){
		cout << "Error adding node: parent does not exist..." << endl;
	}else{
		Node node(n, parentIndex);
		nodes.push_back(node);
		nodes[nodes.size()-1].depth = calcDepth(nodes.size()-1);
	}
}

void Tree::editNode(unsigned i, string n = NOCHANGE, short d = -1, int p = -1){
	if(!(n.compare(NOCHANGE) ==0)){
		nodes[i].name = n;		
	}
	if(strictDepth){
		nodes[i].depth = calcDepth(i);
	}else{
		if(d > -1) nodes[i].depth = d;
	}
	if(p >= 0){
		nodes[i].parent = p;
		if(strictDepth){
			nodes[i].depth = (nodes[p].depth + 1);
		}
	}
	else nodes[i].parent = -1;
}

void Tree::delNode(unsigned i){
	if(nodes.size() != 0 || i < nodes.size()){
		for (int j = i+1; j < nodes.size(); ++j){
			if(nodes[j].parent == i){ //only adjust affected roots
				nodes[j].parent--;
				nodes[j].depth--;
				if(nodes[j].parent == -1){
					nodes[j].root = true;
				}else{
					nodes[j].root = false;
				}
				if(debug){
					string displayParent;
					if(nodes[j].root) 
						displayParent = ROOT;
					else 
						displayParent = nodes[nodes[j].parent].name;
					cout << "Adjusting parent: " << nodes[j].name 
					<< ">>" << displayParent << endl;
				} 
			}
		}
		nodes.erase(nodes.begin()+i);
	}else{
		cout << "Error deleting node: index doesn't exist..." << endl;
	}
}



