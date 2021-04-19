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
    vector<record> dataVector;
}

node::node(record record_)
{
	this->data.push_back(record_);
    this->nodeAirport = record_.origin_airport;
}




void node::processRecords() { //DO THIS ONCE AN AIRPORT IS PICKED!!!!! Simply run me on a node and it will generate dataProcessed, a unordered map of key:airline name value:pair<number of flights, reliability score (out of 100)>
    //first = flight count for this given airline; second = cumlative tardy score
    for (auto it = data.begin(); it != data.end(); ++it) {
        it->generateRecordScore();
        dataProcessed[it->airline].first += 1;
        dataProcessed[it->airline].second += it->tardyScore;
    }
    //right now map is map<airline pair<number of flights, tardyScore>
    
    //read aqquired map entities into an easy-to-use vector of scorecard structures
    for (auto it = dataProcessed.begin(); it != dataProcessed.end(); ++it) {
        scorecard* entry = new scorecard();
        entry->airline = it->first; // POSSIBLE ERROR LOCATION! NEED TO ACCESS NAME!
        entry->flightNumber = it->second.first; //hope this works
        entry->score = it->second.second;

        dataVector.push_back(*entry);
    }

    //first we find the most reliable (smallest average tardy score)
    float mostReliable = FLT_MAX;
    for (auto it = dataVector.begin(); it != dataVector.end(); ++it) {
        if (it->score / it->flightNumber < mostReliable) { //    tardy score / number of flight entries for that given airline
            mostReliable = it->score / it->flightNumber;
        }
    }

    //now we replace score (which is currently tardyness) to score which is reliability (out of 100!)
    for (auto it = dataVector.begin(); it != dataVector.end(); ++it) {
        it->score = (mostReliable / (it->score / it->flightNumber)) * 100;   //(lowest average tardyness / average tardiness of this airline) * 100 = reliability score placed in dataVector->score
    }

    //selection sorting time!
    for (int i = 0; i < dataVector.size() - 1; i++) {
        //float max = dataVector[i].score;
        int maxLoc = i;
        for (int j = i + 1; j < dataVector.size(); j++) {
            if (dataVector[j].score > dataVector[maxLoc].score) {
                maxLoc = j;
            }
        }
        //should only need to happen once, so I won't go about making a function for it
        //string tempName = dataVector[i]->airline;
        //int tempFreq = dataVector[i]->flightNumber;
        //float tempScore = dataVector[i]->score;
        scorecard temp = dataVector[i];
        dataVector[i] = dataVector[maxLoc];
        dataVector[maxLoc] = temp;
    }
}

// writes airline name and score into csv
void node::writeNode(ofstream& infile) {  
	// iterates through dataVector
	infile << "Airline,Score,Number" << "\n";
	for (auto it = dataVector.begin(); it != dataVector.end(); ++it) {
		infile << it->airline << "," << it->score << ", " << it->flightNumber << "\n";
	}
}
