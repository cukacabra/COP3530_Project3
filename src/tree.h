#pragma once
#include <string>
#include "node.h"
#include "record.h"
using namespace std;

struct tree
{
	node* root = nullptr;
	node* getNode(node* rootNode, string airport);
	bool insertNode(node* rootNode, node* inserted);
	void populateTree(vector<node*> nodes);
};