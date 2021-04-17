#pragma once
#include <string>
#include "node.h"
#include "record.h"
using namespace std;

struct tree
{
private:
	node* root = nullptr;

public:
	//tree();
	node* getNode(node* rootNode, string airport);
	bool insertNode(node* rootNode, node* inserted);
};