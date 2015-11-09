//--------------------- Réalistation de la classe City (City.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
//-------------------------------------------------------------Include personnel
#include "City.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques

SensorRoot* City::GetRoot() const
{
	return sensorTree;
}

void City::InsertSensorValue(long int idSensor,unsigned int year,unsigned int month,
		unsigned int day,unsigned int hour, unsigned int minute,
		unsigned int dayWeek, char traffic)
{
	sensorTree->InsertSensorValue(idSensor, year, month, day, hour, minute, dayWeek,
			traffic);
}

void City::SensorStats(int idSensor)
{
	Sensor* sens;

	sensorTree->GetSensor(idSensor, sens);

	float* stats = sens->GetAverageTraffic();

	int i;

	for (i = 0; i < 4; i++)
	{
		*(stats + i) = (int)*(stats + i);
	}

	cout << "V " << *stats << endl;
	cout << "J " << *(stats + 1) << endl;
	cout << "R " << *(stats + 2) << endl;
	cout << "N " << *(stats + 3) << endl;
}

void City::JamPerHour(int weekDay)
{
	Sensor** sensors;
	sensorTree->GetRoot()->GetAllSensors(sensors, sensorTree->GetRoot());
	int nbSensors = sensorTree->GetNbSensors();
	unsigned long int nbEvents = 0;
	unsigned long int tempNbEvents;

	unsigned long int events[24];

	int i, j, k;

	for (i = 0; i < 24; i++)
	{
		events[i] = 0;
	}

	for (i = 0; i < nbSensors; i++)
	{
		for (j = 0; j < 24; j++)
		{
			for (k = 0; k < 60; k++)
			{
				tempNbEvents = (*sensors + i)->GetEvents(weekDay-1, j, k)->GetNbEvents();
				events[j] += tempNbEvents;
				nbEvents += tempNbEvents;
			}
		}
	}

	if (nbEvents != 0)
	{
		for (i = 0; i < 24; i++)
		{
			events[i] = (int)((float)events[i] / nbEvents);
			cout << weekDay << " " << j << " " << events[i] << "%" << endl;
		}
	}
}

void City::JamStatsPerWeekDay(int weekDay)
{
	int nbSensors = sensorTree->GetNbSensors();
	Sensor* sensors = new Sensor[nbSensors];
	sensorTree->GetRoot()->GetAllSensors(&sensors, sensorTree->GetRoot());

	unsigned long int stats[4] = {0, 0, 0, 0};
	unsigned long int nbEvents = 0;

	unsigned long int* tempNumbers = new unsigned long int[4];

	int i, j;

	for (i = 0; i < nbSensors; i++)
	{
		tempNumbers = (sensors + i)->GetNumbersDay(weekDay);
		nbEvents += (sensors + i)->GetNbEventsDay(weekDay);

		for (j = 0; j < 4; j++)
		{
			stats[i] += *(tempNumbers + i);
		}
	}

	if (nbEvents != 0)
	{
		cout << "V " << (int)((float)(*stats * 100) / nbEvents) << "%" << endl;
		cout << "J " << (int)((float)(*(stats + 1) * 100) / nbEvents) << "%" << endl;
		cout << "R " << (int)((float)(*(stats + 2) * 100) / nbEvents) << "%" << endl;
		cout << "N " << (int)((float)(*(stats + 3) * 100) / nbEvents) << "%" << endl;
	}

	else
	{
		cout << "V 0%" << endl;
		cout << "J 0%" << endl;
		cout << "R 0%" << endl;
		cout << "N 0%" << endl;
	}
}

//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

City::City()
{
#ifdef MAP
	cout << "Constructor from City" << endl;
#endif
	sensorTree = new SensorRoot();
}

City::~City ()
{
#ifdef MAP
	cout << "Destructor from City" << endl;
#endif
	delete(sensorTree);
}

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
