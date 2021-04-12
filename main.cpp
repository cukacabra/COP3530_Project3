#include <iomanip>
#include <iostream>
//#include <istream>
#include <fstream>
#include <string>
#include <queue>
#include "record.h"
#include "node.h"
#include <sstream>
using namespace std;

// currently a vector of records
// each record needs a node
// need to organize into binary tree

queue<node> nodes;
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
			node newNode = node(line);
			nodes.push(newNode);
		}
	}
	inFile.close();}

// create and populate table based on root OR could be lowest item in PQ
void populateTable()
{
};

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "Would you like to read in data now? 1 for Yes" << endl;

	/*======= Control loop to input data for testing =======*/
	int option;
	cin >> option;

	if (option == 1) 
	{
		openUserFile("20flights.csv");
	}

	else
	{
		return 0;
	}

	/*======= Create tree =======*/
	// openUserFile created all the nodes in a queue
	


	/*======= Prompt user with choices, get input =======*/
	cout << "1. Do thing" << endl;
	cout << "2. Do other thing" << endl;
	cout << "3. Do anothing thing" << endl;
	cout << "4. Do something" << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Based on the choice, execute the task and show the results =======*/
	if (choice == 1)
	{
		// do thing
	}

	else if (choice == 2)
	{
		// do thing
	}

	else if (choice == 3)
	{
		// do thing

	}

	else if (choice == 4)
	{
		// do thing

	}	

	else if (choice == 0)
	{
		return 0;
	}

	else
	{
		cout << "Invalid Selection" << endl;
	}
	return 0;
}




