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

	unsigned long int events[7][24];

	int i, j, k;

	for (i = 0; i < 24; i++)
		{
			events[weekDay-1][i] = 0;
		}

	for (i = 0; i < nbSensors; i++)
	{
		for (j = 0; j < 24; j++)
		{
			for (k = 0; k < 60; k++)
			{
				tempNbEvents = (*sensors + i)->GetEvents(weekDay-1, j, k)->GetNbEvents();
				events[weekDay-1][j] += tempNbEvents;
				nbEvents += tempNbEvents;
			}
		}
	}

	if (nbEvents != 0)
	{
		for (i = 0; i < 24; i++)
		{
			events[weekDay-1][i] = (int)((float)events[weekDay-1][i] / nbEvents);
			cout << weekDay << " " << j << " " << events[weekDay-1][i] << "%" << endl;
		}
	}
}

//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

City::City()
{
	sensorTree = new SensorRoot();
}

City::~City ()
{
	delete(sensorTree);
}

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
