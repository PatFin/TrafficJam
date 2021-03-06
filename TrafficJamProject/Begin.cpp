/*
 * Begin.cpp
 *
 *  Created on: 6 Nov 2015
 *      Author: patrick
 */

#include "City.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string str;
	City lyon;

	stringstream ss("");
	stringstream ss2("");

	while (cin >> str && str.compare("EXIT")!=0)
	{

		if (str.compare("ADD") == 0)
		{
			long int idSensor;
			unsigned int year;
			unsigned int month;
			unsigned int day;
			unsigned int hour;
			unsigned int minute;
			unsigned int dayWeek;
			char traffic;

			cin >> str;
			ss.str(str);
			ss >> idSensor;
			ss.clear();

			cin >> str;
			ss.str(str);
			ss >> year;
			ss.clear();


			cin >> str;
			ss.str(str);
			ss >> month;
			ss.clear();

			cin >> str;
			ss.str(str);
			ss >> day;
			ss.clear();

			cin >> str;
			ss.str(str);
			ss >> hour;
			ss.clear();

			cin >> str;
			ss.str(str);
			ss >> minute;
			ss.clear();

			cin >> str;
			ss.str(str);
			ss >> dayWeek;
			ss.clear();

			cin >> str;
			ss2.str(str);
			ss2 >> traffic;
			ss2.clear();

			lyon.InsertSensorValue(idSensor, year, month, day, hour, minute, dayWeek, traffic);
		}

		else if (str.compare("STATS_C") == 0)
		{
			cin >> str;
			ss.str(str);

			long int idSensor;
			ss >> idSensor;
			ss.clear();

			lyon.SensorStats(idSensor);
		}

		else if (str.compare("STATS_D7") == 0)
		{
			cin >> str;
			ss.str(str);

			int weekDay;

			ss >> weekDay;
			ss.clear();

			lyon.JamStatsPerWeekDay(weekDay);
		}

		else if (str.compare("JAM_DH") == 0)
		{
			cin >> str;
			ss.str(str);

			int weekDay;

			ss >> weekDay;
			ss.clear();

			lyon.JamPerHour(weekDay);
		}

	}


	return 0;
}
