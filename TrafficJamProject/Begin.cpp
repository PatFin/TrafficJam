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
			stringstream ss(str);
			ss >> idSensor;


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
			ss >> traffic;

			lyon.InsertSensorValue(idSensor, year, month, day, hour, minute, dayWeek, traffic);
			cout << idSensor << " " << year << " " <<  month << " " <<  day << " " <<  hour << " " <<  minute << " " <<  dayWeek << " " <<  traffic << endl;
		}

	}


	return 0;
}
