using namespace std;

#include "SensorRoot.h"

void TestTree();
void TestTree2();

int main()
{
	TestTree2();
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

void TestTree2()
{
	SensorRoot * r = new SensorRoot();
	r->InsertSensorValue(1, 2015, 9, 24, 14, 15, 4, 'V');
	r->InsertSensorValue(2, 2015, 9, 24, 14, 15, 4, 'N');

	Sensor ** sensors = r->GetAllSensors();

	cout << "sensors [0] " << sensors[0]->GetId() <<  endl;
	sensors[0]->DisplayStats();
	cout << "sensors [1] " << sensors[1]->GetId() << endl;
	sensors[1]->DisplayStats();

	delete r;
}
