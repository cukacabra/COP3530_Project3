#pragma once
#include <string>
#include "record.h"
using namespace std;

struct node
{
private:
	node* leftChild = nullptr;
	node* rightChild = nullptr;
	record data;

public:
	node(record);

	// create parent, etc
};