//--------------------- Inteface de la classe City (City.h) ----------------------
#if ! defined (City_H)
#define City_H


//--------------------------------------------------------- Interfaces utilisées
#include "SensorRoot.h"
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
	void InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,
			unsigned int day,unsigned int hour, unsigned int minute,
			unsigned int dayWeek, char traffic);
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
	City();
	// Mode d'emploi :
	//	This constructor allows the user to create a new city with an empty tree
	//	of Sensors.
	// Contrat :
	//	No contract.
	
	virtual ~City ();
	// Mode d'emploi :
	//	This destructor allows the user to clear the object previously created.
	// Contract :
	//	No contract.
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	//--------------------------------------------------------Attributs protégés
	SensorRoot * sensorTree;
};

//-----------------------------------------Autres définitions dépendantes de City

#endif // ! defined (City_H)
