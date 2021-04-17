#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"
#include <sstream>
using namespace std;

node::node()
{
    node* leftChild = nullptr;
    node* rightChild = nullptr;

    string nodeAirport = "";
    vector<record> data;
}

node::node(record record_)
{
	this->data.push_back(record_);
}
