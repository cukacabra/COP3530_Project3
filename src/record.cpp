#include "record.h"
#include <vector>
#include <queue>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

record::record(string lineItem_)
{
	vector<string> lineItemVector;
	//queue<string> lineItemVector;
	stringstream ss(lineItem_);
	//int counter = 1;
	while (ss.good())
	{
		string tempString;
		getline(ss, tempString, ',');
		if (tempString == "")
		{
			tempString = "0";
		}
		lineItemVector.push_back(tempString);
		//cout << counter << " temp string: " << tempString << endl;
		//counter++;
	}
	// we can discuss vector vs queue for the dataset
	year = stoi(lineItemVector[0]);
	month = stoi(lineItemVector[1]);
	day = stoi(lineItemVector[2]);
	day_of_week = lineItemVector[3];
	airline = lineItemVector[4];
	flight_number = stoi(lineItemVector[5]);
	tail_number = lineItemVector[6];
	origin_airport = lineItemVector[7];
	destination_airport = lineItemVector[8];
	scheduled_departure = stoi(lineItemVector[9]);
	departure_time = stoi(lineItemVector[10]);
	departure_delay = stoi(lineItemVector[11]);
	taxi_out = stoi(lineItemVector[12]);
	wheels_off = stoi(lineItemVector[13]);
	scheduled_time = stoi(lineItemVector[14]);
	elapsed_time = stoi(lineItemVector[15]);
	air_time = stoi(lineItemVector[16]);
	distance = stoi(lineItemVector[17]);
	wheels_on = stoi(lineItemVector[18]);
	taxi_in = stoi(lineItemVector[19]);
	scheduled_arrival = stoi(lineItemVector[20]);
	arrival_time = stoi(lineItemVector[21]);
	arrival_delay = stoi(lineItemVector[22]);
	diverted = stoi(lineItemVector[23]);
	cancelled = stoi(lineItemVector[24]);
	// what is all this stuff below here? VVV, not represented in flights20
	cancellation_reason = lineItemVector[25];
	air_system_delay = 0;
	security_delay = stoi(lineItemVector[27]);
	airline_delay = stoi(lineItemVector[28]);
	late_aircraft_delay = stoi(lineItemVector[29]);
	weather_delay = stoi(lineItemVector[30]);

	tardyScore = 0;


		/*year = stoi(lineItemVector.front());
		lineItemVector.pop();

		month = stoi(lineItemVector.front());
		lineItemVector.pop();

		day = stoi(lineItemVector.front());
		lineItemVector.pop();

		day_of_week = stoi(lineItemVector.front());
		lineItemVector.pop();

		airline = lineItemVector.front();
		lineItemVector.pop();

		flight_number = stoi(lineItemVector.front());
		lineItemVector.pop();

		tail_number = lineItemVector.front();
		lineItemVector.pop();

		origin_airport = lineItemVector.front();
		lineItemVector.pop();

		destination_airport = lineItemVector.front();
		lineItemVector.pop();

		scheduled_departure = stoi(lineItemVector.front());
		lineItemVector.pop();

		departure_time = stoi(lineItemVector.front());
		lineItemVector.pop();

		departure_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		taxi_out = stoi(lineItemVector.front());
		lineItemVector.pop();

		wheels_off = stoi(lineItemVector.front());
		lineItemVector.pop();

		scheduled_time = stoi(lineItemVector.front());
		lineItemVector.pop();

		elapsed_time = stoi(lineItemVector.front());
		lineItemVector.pop();

		air_time = stoi(lineItemVector.front());
		lineItemVector.pop();

		distance = stoi(lineItemVector.front());
		lineItemVector.pop();

		wheels_on = stoi(lineItemVector.front());
		lineItemVector.pop();

		taxi_in = stoi(lineItemVector.front());
		lineItemVector.pop();

		scheduled_arrival = stoi(lineItemVector.front());
		lineItemVector.pop();

		arrival_time = stoi(lineItemVector.front());
		lineItemVector.pop();

		arrival_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		diverted = stoi(lineItemVector.front());
		lineItemVector.pop();

		cancelled = stoi(lineItemVector.front());
		lineItemVector.pop();

		cancellation_reason = lineItemVector.front();
		lineItemVector.pop();

		air_system_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		security_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		airline_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		late_aircraft_delay = stoi(lineItemVector.front());
		lineItemVector.pop();

		weather_delay = stoi(lineItemVector.front());
		lineItemVector.pop();*/

	// 1. as reading in records, check to see if airport node exists.
	// if not, create
	// 2. create set of all airport codes as reading in records
	//create tree nodes and assign records (less efficient method)

}

// default constructor
record::record()
{
	year = 1900;
	month = 0;
	day = 0;
	day_of_week = "NA";
	tardyScore = 0;
}
// other record relate methods
// getThis, getThat, etc.


void record::generateRecordScore() {
	if (cancelled != 0) { //if cancelled, 100 score! Very very bad!
		tardyScore = 100;
		return;
	}
	if (diverted != 0) { //if diverted, 80 score! You might get your destination, but much slower!
		tardyScore = 80;
		return;
	}
	if (airline_delay > 50) { //airline delay is 50, before it is considered to be at its maximum
		tardyScore += 40;
	}
	else if (airline_delay > 0) {
		tardyScore += 0.8 * abs(arrival_delay);
	}
	if (taxi_in + taxi_out > 50) { //total taxi time is 50, before it is considered to be at its maximum; nobody likes taxi-ing
		tardyScore += 20;
	}
	else if (taxi_in + taxi_out > 0) {
		tardyScore += 0.4 * abs(arrival_delay);
	}
	return;
}