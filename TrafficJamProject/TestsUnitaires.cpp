using namespace std;

#include "City.h"

void TestTree();
void TestTree2();
void TestEvent();
void TestEventList();
void TestSensor();
void TestCity();

int main()
{
	//TestTree();
	//TestTree2();
	//TestEvent();
	//TestEventList();
	TestSensor();

	return 0;
}

void TestTree()
{
	Sensor* sens;
	City c;

	SensorRoot * r = c.GetRoot();

	r->InsertSensorValue(2, 2015, 10, 30, 21, 33, 1, 'V');
	r->InsertSensorValue(1, 2015, 10, 26, 21, 33, 1, 'R');
	r->InsertSensorValue(3, 2015, 10, 27, 21, 33, 1, 'J');
	r->InsertSensorValue(4, 2015, 10, 26, 21, 33, 1, 'V');
	r->InsertSensorValue(5, 2015, 10, 26, 21, 33, 1, 'R');
	r->InsertSensorValue(6, 2015, 10, 27, 21, 33, 1, 'N');
	r->InsertSensorValue(0, 2015, 10, 15, 02, 33, 2, 'N');

	cout << "Trouve-t-on les Sensor?" << endl;
	cout << r->GetSensor(6, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(5, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(4, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(3, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(2, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(1, sens) << endl;
	cout << *sens << endl;
	cout << r->GetSensor(0, sens) << endl;
	cout << *sens << endl;

	cout << "Appel StatsPerWeekDay" << endl;
	c.JamStatsPerWeekDay(1);
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

void TestEvent()
{
	cout << "Creation of a default event." << endl;

	Event* ev = new Event();

	cout << "Display of the information in this event :" << endl;

	cout << *ev << endl;

	delete ev;

	cout << "Creation of an event with date 2015/11/10 and state V." << endl;

	ev = new Event(2015, 11, 10, 'V');

	cout << "Display of this event :" << endl;

	cout << *ev << endl;

	cout << "Checking that this event has no next :" << endl;

	if (ev->HasNext())
	{
		cout << "This event has a next." << endl;
	}
	else
	{
		cout << "This event has no next." << endl;
	}

	delete ev;
}

void TestEventList()
{
	cout << "Creation of an empty event list." << endl;

	EventList* list = new EventList();

	cout << "Checking that this list is empty :" << endl;

	if (list->IsEmpty())
	{
		cout << "This list is empty." << endl;
	}
	else
	{
		cout << "This list is not empty." << endl;
	}

	cout << "Adding an event at date 2015/11/10, traffic state 'J'." << endl;

	list->AddEvent(new Event(2015, 11, 10, 'J'));

	cout << "Display of the list :" << endl;

	cout << *list << endl;

	cout << "Adding another event, at date 2015/11/9, state 'N'." << endl;

	list->AddEvent(new Event(2015, 11, 9, 'N'));

	cout << "Checking that this event has been added at the head of the list :"
		 << endl;

	cout << *list << endl;

	cout << "Checking again that this list is not empty :" << endl;

	if (list->IsEmpty())
	{
		cout << "This list is empty." << endl;
	}
	else
	{
		cout << "This list is not empty." << endl;
	}

	cout << "Display of the traffic numbers in this list :" << endl;

	unsigned long int* numbers = list->GetTrafficNumbers();

	cout << "V : " << *(numbers) << endl;
	cout << "J : " << *(numbers + 1) << endl;
	cout << "R : " << *(numbers + 2) << endl;
	cout << "N : " << *(numbers + 3) << endl;

	cout << "Checking that there are 2 events in the list :" << endl;

	cout << "There are " << list->GetNbEvents() << " events in this list." << endl;

	delete list;
}

void TestSensor()
{
	cout << "Creation of a default sensor." << endl;

	Sensor* sens = new Sensor();

	cout << "Display of this sensor :" << endl;

	cout << *sens << endl;

	delete sens;

	cout << "Creation of a sensor of identificator 1." << endl;

	sens = new Sensor(1);

	cout << "Display of this sensor :" << endl;

	cout << *sens << endl;

	cout << "Adding an event at date 2015/11/10, 17:05, day of the week 2, "
		 << "traffic state V." << endl;

	sens->AddEvent(2015, 11, 10, 17, 5, 2, 'R');

	cout << "Display of the sensor :" << endl;

	cout << *sens << endl;

	cout << "Adding another event at date 2015/10/9, 15:10, day of the week 5, "
		 << "traffic state V" << endl;

	sens->AddEvent(2015, 10, 9, 15, 10, 5, 'V');

	cout << "Display of the sensor :" << endl;

	cout << *sens << endl;

	delete sens;
}
