/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
long int Sensor::GetId() const
// Algorithme :
//
	{
		return id;
	} //----- Fin de Méthode

EventList* Sensor::GetEvents(unsigned int d, unsigned int h, unsigned int m) const
// Algorithme :
//
	{
		return events[d-1][h][m];
	} //----- Fin de Méthode

unsigned long int* Sensor::GetTrafficNumbers()
// Algorithme :
//
	{
		return trafficNumbers;
	} //----- Fin de Méthode

unsigned long int Sensor::GetNbEvents()
// Algorithme :
//
	{
		return nbOfEvents;
	} //----- Fin de Méthode

unsigned long int Sensor::GetNbEventsDay(int weekDay) const
// Algorithme :
//
{
	unsigned long int nbOfEvents = 0;

	int i, j;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 60; j++)
		{
			nbOfEvents += events[weekDay - 1][i][j]->GetNbEvents();
		}
	}

	return nbOfEvents;
} //----- Fin de Méthode

void Sensor::AddEvent(unsigned int year, unsigned int month, unsigned int day,
    			  unsigned int hour, unsigned int minute, unsigned int d7,
				  char state)
// Algorithme :
//
	{
		events[d7-1][hour][minute]->AddEvent(new Event(year, month, day, state));

		switch (state)
		{
		case 'V' :
			trafficNumbers[0]++;
			break;

		case 'J' :
			trafficNumbers[1]++;
			break;

		case 'R' :
			trafficNumbers[2]++;
			break;

		case 'N' :
			trafficNumbers[3]++;
			break;
		}

		nbOfEvents++;
	} //----- Fin de Méthode

float* Sensor::GetAverageTraffic() const
// Algorithme :
//
	{
		float* averageTraffic = new float [4];

		int i;

		for (i = 0; i < 4; i++)
		{
			if (nbOfEvents != 0)
			{
				averageTraffic[i] = (float)trafficNumbers[i] / nbOfEvents;
			}
			else
			{
				averageTraffic[i] = 0;
			}
		}

		return averageTraffic;
	} //----- Fin de Méthode

unsigned long int* Sensor::GetNumbersDay(int weekDay) const
{
	unsigned long int* numbers = new unsigned long int[4];
	unsigned long int nbOfEvents = 0;

	unsigned long int* tempNumbers;

	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		*(numbers + i) = 0;
	}

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 60; j++)
		{
			tempNumbers = events[weekDay - 1][i][j]->GetTrafficNumbers();
			nbOfEvents += events[weekDay - 1][i][j]->GetNbEvents();

			for (k = 0; k < 4; k++)
			{
				*(numbers + k) += *(tempNumbers + k);
			}
		}
	}

	return numbers;
}

void Sensor::DisplayStats() const
{
	float* stats = GetAverageTraffic();

	cout << "V " << (int)((*stats)*100) << "%" << endl;
	cout << "J " << (int)((*(stats + 1))*100) << "%" << endl;
	cout << "R " << (int)((*(stats + 2))*100) << "%" << endl;
	cout << "N " << (int)((*(stats + 3))*100) << "%" << endl;
}


//------------------------------------------------- Surcharge d'opérateurs
//Sensor & Sensor::operator = ( const Sensor & unSensor )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Sensor>" << endl;
//#endif
//} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ()
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au constructeur par défaut de <Sensor>" << endl;
	#endif

    id = 0;
    trafficNumbers = new unsigned long int[4];

    int i, j, k;

    for (i = 0; i < 7; i++)
    {
    	for (j = 0; j < 24; j++)
    	{
    		for (k = 0; k < 60; k++)
    		{
    			events[i][j][k] = new EventList();
    		}
    	}
    }

    for (i = 0; i < 4; i++)
    {
    	trafficNumbers[i] = 0;
    }

    nbOfEvents = 0;
} //----- Fin de Sensor

Sensor::Sensor (long int aId)
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur de <Sensor>" << endl;
	#endif

    id = aId;
    trafficNumbers = new unsigned long int[4];

    int i, j, k;

    for (i = 0; i < 7; i++)
    {
       	for (j = 0; j < 24; j++)
       	{
       		for (k = 0; k < 60; k++)
       		{
       			events[i][j][k] = new EventList();
       		}
       	}
    }

    for (i = 0; i < 4; i++)
        {
        	trafficNumbers[i] = 0;
        }

    nbOfEvents = 0;
} //----- Fin de Sensor


Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif

    int i, j, k;

    for (i = 0; i < 7; i++)
    {
    	for (j = 0; j < 24; j++)
    	{
    		for (k = 0; k < 60; k++)
    		{
    			delete events[i][j][k];
    		}
    	}
    }

    delete[] trafficNumbers;
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
