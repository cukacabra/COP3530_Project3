#include <iomanip>
#include <iostream>
//#include <istream>
#include <fstream>
#include <string>
#include <queue>
#include "record.h"
#include "node.h"
#include "tree.h"
#include "scorecard.h"
#include <sstream>
#include <iterator>
using namespace std;

// currently a vector of records
// each record needs a node
// need to organize into binary tree

vector<node*> nodes; //needs to be made into a binary tree of members node.
string userSelection;

void openUserFile(string userPick)
{
	ifstream inFile(userPick); // fileStream Object
	if (inFile.is_open())
	{
		cout << "Opened csv: " << endl;
		//read line from file to string line
		string line;
		getline(inFile, line);

		while (getline(inFile, line))
		{
			//cout << "new line input: " << line << endl; // print ever line to test
			//node* newNode = node(line);
			//
			record newRecord = record(line);
			bool temp = true;
			// check vector of nodes
			//std::vector<node>::iterator it; 
			for (int i = 0; i < nodes.size(); i++)
			{
				if (nodes[i]->nodeAirport == newRecord.origin_airport)
				{
					nodes[i]->data.push_back(newRecord);
					temp = false;
					break;
				}
			}
			if (temp) {
				node* newNode = new node(newRecord);
				nodes.push_back(newNode);
			}
		}
	}
	inFile.close();
}




int main()
{
	tree myTree;
	// cout << "Which file(s) to open?\n";
	cout << "Would you like to read in airline data now? 1 for Yes" << endl;

	/*======= Control loop to input data for testing =======*/
	int option;
	cin >> option;

	if (option == 1)
	{
		openUserFile("./input/flights.csv");
		myTree.populateTree(nodes);
		//change name
	}

	else
	{
		return 0;
	}

	/*======= Create tree =======*/
	// openUserFile created all the nodes in a queue



	/*======= Prompt user with choices, get input =======*/
	cout << "1. Learn more about an airport." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Based on the choice, execute the task and show the results =======*/
	if (choice == 1)
	{
		cout << "Input a 3 character airport code such as PHL, LAX, or SEA:" << endl;
		string airportCode;
		cin >> airportCode;
		node* myNode = myTree.getNode(myTree.root, airportCode);
		myNode->processRecords();

		// generates csv file
		ofstream myfile;
		myfile.open("./output/scores2.csv");
		myNode->writeNode(myfile);
		myfile.close();
		
		//runs rscript to visualize graph
		string rscript;
		cin.ignore();
		cout << "Enter the directory of your Rscript.exe" << endl;
		getline(cin, rscript);

		string cmd_plot = rscript + " plot-scores.r -s output/scores2.csv -o output";
		cout << cmd_plot << endl;
		system(cmd_plot.c_str());
	
		cout << "Please see the output for your results. Have a safe flight!" << endl;

	}

	else
	{
		cout << "Invalid Selection" << endl;
	}
	return 0;
}

