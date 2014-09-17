#ifndef tree_H_
#define tree_H_

#include <vector>
#include <string>
// #include <sstream>

struct Node{
	std::string name;
	bool root;
	short depth;
	int parent;
	Node(std::string n = "Unnamed", int p = -1){
		name = n;
		if(p <= -1){
			root = true;
			depth = 0;
		}
		else{
			root = false;
		}
		parent = p;
	}
};

typedef std::vector<Node> nodeVec;

class Tree{
private:
	string name;
	short depth;
	nodeVec nodes;

	//Settings
	bool strictDepth;

	short calcDepth(unsigned i);
public:
	Tree();
	Tree(string n, bool strictDepth);

	void print(bool verbose);

	unsigned getSize();
	short getDepth();
	int getIndex(string n);

	Node getNode(unsigned i);

	void addNode(Node &n);
	void addNode(string n = "Unnamed", int parentIndex = -1);
	void editNode(unsigned i, string n, short d, int p);
	void delNode(unsigned i);
};

#endif //tree_H_