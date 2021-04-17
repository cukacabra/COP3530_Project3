#pragma once
#include <string>
#include <vector>
#include "record.h"
using namespace std;

struct node
{
public:
	node* leftChild = nullptr;
	node* rightChild = nullptr;

    string nodeAirport = "";
    vector<record> data;

    node();
    node(record);
	// create parent, etc
};