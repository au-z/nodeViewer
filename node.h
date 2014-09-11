#ifndef Node
#define Node

#include <iostream>
#include <string>
using namespace std;

class Node{
	string name;
	bool root;
	Node *parent;
	unsigned treeIndex;
public:
	Node();
	Node(string n, bool r, Node *p);

	string toString(bool all);
	void setParent(Node *p);
	void setName(string n);
	void setRoot(bool r);
	void setTreeIndex(unsigned i);

	Node* getParent();
	string getName();
	bool getRoot();
	unsigned getTreeIndex();

	~Node(){}
};

#endif //Node