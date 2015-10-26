using namespace std;

#include <iostream>
#include "Sensor.h"

int main()
{
	Sensor* sens = new Sensor(3);

	sens->AddEvent(2015, 10, 26, 21, 33, 1, 'V');

	cout << *sens;

	return 0;
}


