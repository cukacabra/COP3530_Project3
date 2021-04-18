#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"
#include "record.h"
#include <sstream>
#include <unordered_map>
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



node::processRecords() { //DO THIS ONCE AN AIRPORT IS PICKED!!!!! Simply run me on a node and it will generate dataProcessed, a unordered map of key:airline name value:pair<number of flights, reliability score (out of 100)>
    //first = flight count for this given airline; second = cumlative tardy score
    for (auto it = data.begin(); it != data.end(); ++it) {
        it.generateRecordScore();
        dataProcessed[it->airline]->first += 1;
        dataProcessed[it->airline]->second += it->tardyscore;
    }
    //right now map is map<airline pair<number of flights, tardyScore>
    //we now turn it into map<airline pair<number of flights, reliability score out of 100> // reliability score is good!

    //first we find the most reliable (smallest average tardy score)
    float mostReliable = FLT_MAX;
    for (auto it2 = dataProcessed.begin(); it2 != dataProcessed.end(); ++it2) {
        if (it2->second / it2->first < mostReliable) { //    tardy score / number of flight entries for that given airline
            mostReliable = it2->second / it2->first;
        }
    }

    //now we all other airlines in proportion to that
    for (auto it3 = dataProcessed.begin(); it3 != dataProcessed.end(); ++it3) {
        it3->second = (mostReliable / (it3->second / it3->first)) * 100;   //(lowest average tardyness / average tardiness of this airline) * 100 = reliability score placed in dataProcessed->second
    }
}
