using namespace std;

#include "SensorRoot.h"

int main()
{
	Sensor* sens;
	SensorRoot r;

	r.InsertSensorValue(0, 2015, 10, 26, 21, 33, 1, 'V');
	r.InsertSensorValue(0, 2015, 10, 26, 21, 33, 1, 'V');
	r.InsertSensorValue(0, 2015, 10, 27, 21, 33, 1, 'V');

	//cout << sens->GetEvents(1, 21, 33)->GetNbEvents() << endl;
	r.GetSensor(0, &sens);
	sens->GetEvents(0, 21, 33)->DisplayList();

	r.InsertSensorValue(1, 2015, 10, 30, 21, 33, 1, 'V');
	r.InsertSensorValue(1, 2015, 10, 26, 21, 33, 1, 'V');
	r.InsertSensorValue(1, 2015, 10, 27, 21, 33, 1, 'V');
	cout << r.GetSensor(1, &sens) << endl;
	sens->GetEvents(1, 21, 33)->DisplayList();

	//cout << *sens << endl;

	return 0;
}


