using namespace std;

#include <iostream>
#include "SensorRoot.h"

int main()
{
	Sensor* sens;

//	sens->AddEvent(2015, 10, 26, 21, 33, 1, 'V');
//	sens->AddEvent(2015, 10, 27, 21, 33, 1, 'V');
//	sens->AddEvent(2015, 10, 26, 21, 33, 2, 'V');

//	cout << sens->GetEvents(1, 21, 33)->GetNbEvents() << endl;


	SensorRoot r;
	r.InsertSensorValue(0, 2015, 10, 26, 21, 33, 1, 'V');
	r.InsertSensorValue(0, 2015, 10, 27, 21, 33, 2, 'V');
	r.InsertSensorValue(0, 2015, 10, 25, 6, 45, 2, 'V');
	r.GetSensor(0, &sens);
	cout << *sens << endl;
	r.InsertSensorValue(1, 2015, 10, 27, 21, 33, 2, 'V');

	return 0;
}


