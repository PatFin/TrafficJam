//--------------------- Inteface de la classe City (City.h) ----------------------
#if ! defined (City_H)
#define City_H


//--------------------------------------------------------- Interfaces utilisées
#include "TreeSensor.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe City
// A City is a represented by a name and a collection of Sensors gathered in an
// instance of TreeSensor.
// It is possible for the user to add events associated with a certain Sensor to
// the city. The dynamic allocation of memory induced is handled by this class
// and it's attributes.
//------------------------------------------------------------------------------

class City
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	int InsertValue (int idSensor, int year, int month, int day, int hour,
			int minute, int dayWeek, char traffic);
	// Mode d'emploi :
	// 	Allows to add a new Event to the sensor whose id is that of the first
	// 	parameter.
	// Contrat :
	//	No contract.

	void SensorStats(int idSensor);
	// Mode d'emploi :
	//	Shows the statistics for a specific sensor.
	// Contrat :
	//	The idSensor must match an existing sensor in the city. Otherwise the
	//	method will fail.
	void JamPerHour(int weekDay);
	// Mode d'emploi :
	//	Shows the percentage of traffic jam for each hour in a day of the week.
	// Contrat :
	//	No contract.
	void JamStatsPerWeekDay(int weekDay);
	// Mode d'emploi :
	//	Shows the traffic statistics for a specific day of the week.
	// Contrat :
	//	No contract.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	City ();
	// Mode d'emploi :
	//	This constructor allows the user to create a new city with an empty tree
	//	of Sensors.
	// Contrat :
	//	No contract.
	
	virtual ~City ();
	// Mode d'emploi :
	//	This desstructor allows the user to clear the object previously created.
	// Contrat :
	//	No contract.
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	//--------------------------------------------------------Attributs protégés
	TreeSensor * sensorTree;
};

//-----------------------------------------Autres définitions dépendantes de City

#endif // ! defined (City_H)
