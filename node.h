#pragma once
#include <string>
#include <vector>
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
    unordered_map<String, pair<int, float>> dataProcessed; //String airline name, int (first) is number of records recorded, float (second) is their reliabilty score out of 100
    vector<scorecard> dataVector;
    //this way we can access int (first) to give us a sample size for our reliability score rating.

    node();
    node(record);
    void processRecords();
    //void selectionsort();
	// create parent, etc
};