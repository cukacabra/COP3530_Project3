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
	bool checkNode(string airport);
	// create parent, etc
};