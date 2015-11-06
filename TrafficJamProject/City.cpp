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

void City::InsertSensorValue(long int idSensor,unsigned int year,unsigned int month,
		unsigned int day,unsigned int hour, unsigned int minute,
		unsigned int dayWeek, char traffic)
{
	sensorTree->InsertSensorValue(idSensor, year, month, day, hour, minute, dayWeek,
			traffic);
}

void City::SensorStats(int idSensor)
{
	Sensor** sens;

	sensorTree->GetSensor(idSensor, sens);

	float* stats = (*sens)->GetAverageTraffic();

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
	Sensor** sensors = sensorTree->GetRoot()->GetAllSensors(sensors, sensorTree->GetRoot());

	int nbSensors = sensorTree->GetNbSensors();
	unsigned long int nbEvents = 0;
	unsigned long int tempNbEvents;

	unsigned long int events[7][24];

	int i, j, k, l;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 24; j++)
		{
			events[i][j] = 0;
		}
	}

	for (i = 0; i < nbSensors; i++)
	{
		for (j = 0; j < 7; j++)
		{
			for (k = 0; k < 24; k++)
			{
				for (l = 0; l < 60; l++)
				{
					tempNbEvents = (*sensors + i)->GetEvents(j, k, l)->GetNbEvents();
					events[j][k] += tempNbEvents;
					nbEvents += tempNbEvents;
				}
			}
		}
	}

	if (nbEvents != 0)
	{
		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 24; j++)
			{
				events[i][j] = (int)((float)events[i][j] / nbEvents);

				cout << i+1 << " " << j << " " << events[i][j] << "%" << endl;
			}
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
