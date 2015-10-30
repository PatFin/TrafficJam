using namespace std;

#include <iostream>
#include "Sensor.h"

int main()
{
	Sensor* sens = new Sensor(3);

	sens->AddEvent(2015, 10, 26, 21, 33, 1, 'V');
	sens->AddEvent(2015, 10, 27, 21, 33, 1, 'V');
	sens->AddEvent(2015, 10, 28, 21, 33, 1, 'V');
	sens->AddEvent(2015, 10, 26, 21, 33, 2, 'V');

	//cout << sens->GetEvents(1, 21, 33)->GetNbEvents() << endl;

	sens->GetEvents(1, 21, 33)->DisplayList();

	//sens->GetEvents(2, 21, 33)->DisplayList();

	//cout << *sens << endl;

	return 0;
}


