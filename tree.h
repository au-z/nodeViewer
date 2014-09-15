#ifndef tree_H_
#define tree_H_

#include <vector>
#include <string>

struct Node{
	std::string name;
	bool root;
	struct Node *parent;
	Node(std::string n = "Unnamed", Node *p = NULL){
		name = n;
		if(p == NULL) root = true;
		else root = false;
		parent = p;
	}
};

typedef std::vector<Node *> nodeVec;  

class Tree{
private:
	std::string name;
	int depth;
	nodeVec nodes;
	vector<int> testVec;
public:
	// Tree(string n, nodeVec import);
	Tree();
	Tree(const nodeVec &n);

	~Tree();

	void print();

	unsigned getSize();
	short getDepth();
	int getIndex(std::string n);

	Node getNode(unsigned i);

	void add2Test(int i);
	void addNode(Node* n);
	void addNode(string n = "Unnamed", int parentIndex = -1);
	void delNode(unsigned i);
	void editNode(unsigned i, std::string n, Node *p);
};

#endif //tree_H_