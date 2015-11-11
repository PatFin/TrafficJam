using namespace std;

#include "SensorRoot.h"

void TestTree();

int main()
{
	TestTree();
	return 0;
}

void TestTree()
{
	Sensor* sens;
	SensorRoot r;

	r.InsertSensorValue(2, 2015, 10, 30, 21, 33, 1, 'V');
	r.InsertSensorValue(1, 2015, 10, 26, 21, 33, 1, 'R');
	r.InsertSensorValue(3, 2015, 10, 27, 21, 33, 1, 'J');
	r.InsertSensorValue(4, 2015, 10, 26, 21, 33, 1, 'V');
	r.InsertSensorValue(5, 2015, 10, 26, 21, 33, 1, 'R');
	r.InsertSensorValue(6, 2015, 10, 27, 21, 33, 1, 'N');
	r.InsertSensorValue(0, 2015, 10, 15, 02, 33, 2, 'N');

	cout << "Trouve-t-on les Sensor?" << endl;
	cout << r.GetSensor(6, sens) << endl;
	cout << r.GetSensor(5, sens) << endl;
	cout << r.GetSensor(4, sens) << endl;
	cout << r.GetSensor(3, sens) << endl;
	cout << r.GetSensor(2, sens) << endl;
	cout << r.GetSensor(1, sens) << endl;
	cout << r.GetSensor(0, sens) << endl;

}


//Sensor* sens;
//	SensorRoot r;
//
//	r.InsertSensorValue(2, 2015, 10, 30, 21, 33, 1, 'V');
//	r.InsertSensorValue(1, 2015, 10, 26, 21, 33, 1, 'R');
//	r.InsertSensorValue(3, 2015, 10, 27, 21, 33, 1, 'J');
//
//	r.InsertSensorValue(2, 2015, 10, 30, 21, 33, 1, 'R');
//	r.InsertSensorValue(1, 2015, 10, 26, 21, 33, 1, 'J');
//	r.InsertSensorValue(3, 2015, 10, 27, 21, 33, 1, 'N');
//
//	r.InsertSensorValue(4, 2015, 10, 26, 21, 33, 1, 'V');
//	r.InsertSensorValue(5, 2015, 10, 26, 21, 33, 1, 'R');
//	r.InsertSensorValue(6, 2015, 10, 27, 21, 33, 1, 'N');
//	r.InsertSensorValue(0, 2015, 10, 15, 02, 33, 2, 'N');
//
//
//	r.InsertSensorValue(8, 2015, 10, 30, 21, 33, 1, 'V');
//	r.InsertSensorValue(9, 2015, 10, 26, 21, 33, 1, 'V');
//	r.InsertSensorValue(7, 2015, 10, 26, 21, 33, 1, 'V');
//
//	cout << "Trouve-t-on les Sensor?" << endl;
//
//	cout << r.GetSensor(8, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(9, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(7, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(6, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(5, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(4, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(3, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(2, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(1, sens) << endl;
//	sens->DisplayStats();
//	cout << r.GetSensor(0, sens) << endl;
//	sens->DisplayStats();
