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

	int res = sensorTree->GetSensor(idSensor, sens);

	if (res == 0)
	{
		float* stats = sens->GetAverageTraffic();

		cout << "V " << (int)(*stats * 100) << "%" << endl;
		cout << "J " << (int)(*(stats + 1) * 100) << "%" << endl;
		cout << "R " << (int)(*(stats + 2) * 100) << "%" << endl;
		cout << "N " << (int)(*(stats + 3) * 100) << "%" << endl;
	}

	else
	{
		cout << "V 0%" << endl;
		cout << "J 0%" << endl;
		cout << "R 0%" << endl;
		cout << "N 0%" << endl;
	}
}

void City::JamPerHour(int weekDay)
{
	Sensor** sensors = sensorTree->GetAllSensors();
	int nbSensors = sensorTree->GetNbSensors();
	unsigned long int* nbEvents = new unsigned long int[24];
	unsigned long int tempNbEvents;

	unsigned long int** stats = new unsigned long int*[24];
	unsigned long int* tempStats;
	unsigned long int* trafficRN = new unsigned long int[24];

	int i, j, k, l;

	/*
	Initialisation du tableau contenant le nombre d'évènements pour chaque heure,
	suivant leur état.
	 */

	for (i = 0; i < 24; i++)
	{
		stats[i] = new unsigned long int[4];
	}

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 4; j++)
		{
			stats[i][j] = 0;
		}
		trafficRN[i] = 0;
	}

	/*
	Initialisation du tableau contenant le nombre total d'évènements par heure.
	 */

	for (i = 0; i < 24; i++)
	{
		nbEvents[i] = 0;
	}

	for (i = 0; i < nbSensors; i++)
	{
		for (j = 0; j < 24; j++)
		{
			for (k = 0; k < 60; k++)
			{
				tempNbEvents = sensors[i]->GetEvents(weekDay, j, k)->GetNbEvents();

				tempStats = sensors[i]->GetEvents(weekDay, j, k)->GetTrafficNumbers();

				nbEvents[j] += tempNbEvents;

				for (l = 0; l < 4; l++)
				{
					stats[j][l] += *(tempStats + l);
				}
			}

			trafficRN[j] = (stats[j][2] + stats[j][3]);
		}
	}

	for (i = 0; i < 24; i++)
	{
		cout << weekDay << " " << i << " ";

		if (nbEvents[i] != 0)
		{
			cout << (int)((float)(trafficRN[i]) / nbEvents[i] * 100) << "%" << endl;
		}

		else
		{
			cout << "0%" << endl;
		}
	}

	for (i = 0; i < 24; i++)
		{
			delete[] stats[i];
		}

	delete[] stats;
	delete[] trafficRN;
}

void City::JamStatsPerWeekDay(int weekDay)
{
	int nbSensors = sensorTree->GetNbSensors();
	Sensor ** sensors = sensorTree->GetAllSensors();

	unsigned long int* stats = new unsigned long int[4];
	unsigned long int nbEvents = 0;

	unsigned long int* tempNumbers;

	int i, j;

#ifdef MAP
	for (i = 0; i < nbSensors; i++)
	{
		cout << "--" <<*(sensors[i]) << endl;
	}
#endif

	for (i = 0; i < 4; i++)
	{
		stats[i] = 0;
	}

	for (i = 0; i < nbSensors; i++)
	{
		tempNumbers = sensors[i]->GetNumbersDay(weekDay);
		nbEvents += sensors[i]->GetNbEventsDay(weekDay);

		for (j = 0; j < 4; j++)
		{
			stats[j] += *(tempNumbers + j);
		}
	}

	if (nbEvents != 0)
	{
		cout << "V " << (int)((float)(*stats) / nbEvents * 100) << "%" << endl;
		cout << "J " << (int)((float)(*(stats + 1)) / nbEvents * 100) << "%" << endl;
		cout << "R " << (int)((float)(*(stats + 2)) / nbEvents * 100) << "%" << endl;
		cout << "N " << (int)((float)(*(stats + 3)) / nbEvents * 100) << "%" << endl;
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
	cout << "--Constructor from <City>" << endl;
#endif
	sensorTree = new SensorRoot();
}

City::~City ()
{
#ifdef MAP
	cout << "--Destruction of <City>" << endl;
#endif
	delete(sensorTree);
}

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
