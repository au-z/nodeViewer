#ifndef Tree
#define Tree

#include <iostream>
#include <string>
#include <vector>
#include "node.h"
using namespace std;

class Tree{
	string name;
	vector<Node> nodes;
	int size;
	int depth;
public:
	Tree();
	Tree(string n, vector<Node> import);

	~Tree();

	string toString();

	unsigned getSize();
	short getDepth();

	void addNode(Node n);
	void delNode(unsigned i);
	void editNode(unsigned i, string n, bool r, Node *p);
};

#endif //Tree