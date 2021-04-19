#pragma once
#include <string>
using namespace std;
/*
**FILE FIELDS**
YEAR,MONTH,DAY,DAY_OF_WEEK,AIRLINE,FLIGHT_NUMBER,TAIL_NUMBER,ORIGIN_AIRPORT,DESTINATION_AIRPORT,
SCHEDULED_DEPARTURE,DEPARTURE_TIME,DEPARTURE_DELAY,TAXI_OUT,WHEELS_OFF,SCHEDULED_TIME,
ELAPSED_TIME,AIR_TIME,DISTANCE,WHEELS_ON,TAXI_IN,SCHEDULED_ARRIVAL,ARRIVAL_TIME,ARRIVAL_DELAY,
DIVERTED,CANCELLED,CANCELLATION_REASON,AIR_SYSTEM_DELAY,SECURITY_DELAY,AIRLINE_DELAY,
LATE_AIRCRAFT_DELAY,WEATHER_DELAY
**CALCULATED FIELDS**
int score;
*/
class record
{

private:
	int year;
	int month;
	int day;
	string day_of_week;
	string airline;
	int flight_number;
	string tail_number;
	string origin_airport;
	string destination_airport;
	int scheduled_departure;
	int departure_time;
	int departure_delay;
	int taxi_out;
	int wheels_off;
	int scheduled_time;
	int elapsed_time;
	int air_time;
	int distance;
	int wheels_on;
	int taxi_in;
	int scheduled_arrival;
	int arrival_time;
	int arrival_delay;
	int diverted;
	int cancelled;
	string cancellation_reason;
	int air_system_delay;
	int security_delay;
	int airline_delay;
	int late_aircraft_delay;
	int weather_delay;
	

public:
	record();
	record(string lineitem_);
	void generateRecordScore(); 
	string airline;
	int score;
	float tardyScore; //in this context, bigger score means LESS reliable
};
