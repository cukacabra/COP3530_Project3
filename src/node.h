#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "record.h"
#include "scorecard.h"
using namespace std;

struct node
{
public:
	node* leftChild = nullptr;
	node* rightChild = nullptr;

    string nodeAirport = "";
    vector<record> data;
    unordered_map<string, pair<int, float>> dataProcessed; //String airline name, int (first) is number of records recorded, float (second) is their reliabilty score out of 100
    vector<scorecard> dataVector;
    //this way we can access int (first) to give us a sample size for our reliability score rating.

    node();
    node(record);
    void processRecords();
    void writeNode(ofstream& infile);
	// create parent, etc
};