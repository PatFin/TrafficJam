/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ------
#if ! defined ( SENSOR_H_ )
#define SENSOR_H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "EventList.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role of class <Sensor>
//
// A sensor gathers all the events
//------------------------------------------------------------------------ 
using namespace std;
class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	long int GetId() const;
	// Usage:
	//	Returns the identificator of the Sensor.
	//
	// Contract:
	// No contract.

	EventList* GetEvents(unsigned int d, unsigned int h, unsigned int m) const;
	// Usage:
	//	Returns an array containing all the events for a certain day of the week,
	//	hour, minute.
	// Contract:
	//	d must be set between 1 and 7, h between 0 and 23, m between 0 and 59.
	//	The parameters must be of the right type, and in the right order.

	unsigned long int* GetTrafficNumbers();
	// Usage:
	//	Returns, in an array, the number of events for each traffic state,
	//	contained in the sensor.
	//
	// Contract:
	//	No contract.

	unsigned long int GetNbEvents();
	// Usage:
	//	Returns the total number of events of the sensor.
	//
	// Contract:
	//	No contract.

	unsigned long int GetNbEventsDay(int weekDay) const;
	// Usage:
	//	Returns the number of events for a specific day of the week.
	//
	// Contract:
	//	weekDay must be set between 1 and 7.

    void AddEvent(unsigned int year, unsigned int month, unsigned int day,
    			  unsigned int hour, unsigned int minute, unsigned int d7,
				  char trafficState);
    // Usage:
    //	Inserts an event at the head of the list.
    //
    // Contract:
    // The parameters must be valid (right type and right order).
    // d7 must be set between 1 and 7, hour between 0 and 23,
    // minute between 0 and 59, trafficState must be 'V', 'J', 'R' or 'N'.

    float* GetAverageTraffic() const;
    // Usage:
    // Returns an array containing the traffic statistics (ie the number of
    // occurrences of a traffic state, over the total number of events.
    //
    // Contract:
    // No contract.

    unsigned long int* GetNumbersDay(int weekDay) const;
    // Usage:
    // Returns, in an array, the number of occurrences of each traffic state,
    // for a given day of the week.
    //
    // Contract:
    //	weekDay must be set between 1 and 7.

    void DisplayStats() const;
    // Usage:
    // Displays the percentage of apparition of each traffic state, considering
    // all the events comprised in this sensor.
    //
    // Contract:
    // No contract.


//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Usage:
    //
    // Contract:
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contract:
    //

    Sensor ( );
    // Usage:
    // Creates a standard sensor, with identificator 0.
    //
    // Contract:
    // This constructor should not be used more than once.

    Sensor (long aId);
    // Usage:
    // Creates a sensor with the identificator specified as a parameter.
    //
    // Contract:
    // The user should not use a same identificator more than once.

    virtual ~Sensor ( );
    // Usage:
    //
    // Contract:
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    long int id; // identificator of the sensor

    EventList* events[7][24][60]; /* array containing all the events of the sensor,
    								 sorted by day of the week, hour, minute. */

    unsigned long int trafficNumbers[4]; /* array containing the number of
     	 	 	 	 	 	 	 	 	 	occurrences of each traffic state. */

    unsigned long int nbOfEvents; // total number of events for this sensor

//---------------------------------------------------------- Classes amies

friend std::ostream& operator << (std::ostream &strm, const Sensor & aSensor);

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

inline std::ostream& operator << (std::ostream &strm, const Sensor & aSensor)
// Algorithme :
//
{
	int i, j, k;

	strm << "Sensor " << aSensor.id << " : " << endl << endl;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 24; j++)
		{
			for (k = 0; k < 60; k++)
			{
				if (!aSensor.events[i][j][k]->IsEmpty())
				{
					strm << "day " << i+1 << ", " << j << "h" << k << " : "
						 << endl << *(aSensor.events[i][j][k]) << endl;
				}
			}
		}
	}

	return strm;
} //----- Fin de operator <<

//----------------------------------------- Types dépendants de <Sensor>

#endif // SENSOR_H_
