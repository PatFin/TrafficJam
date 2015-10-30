//--------------------- Réalistation de la classe SensorLeaf (SensorLeaf.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
//-------------------------------------------------------------Include personnel
#include "SensorLeaf.h";
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC
void SensorLeaf::InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,unsigned int day,unsigned int hour, unsigned int minute, unsigned int dayWeek, unsigned int traffic)
// Algorithme :
//	We first look for a sensor in the tree whose id matches that of the one given
//	as parameter.
//	If it was found, then the event is added using method AddEvent of Sensor.
//	If not found, a new Sensor is created and inserted into the tree. Then the
//	event is added to the Sensor.
{
	Sensor * sensor;
	if (GetSensor(idSensor, &sensor) == 1)
	{

	}

	sensor->AddEvent(year,month,day,hour, minute, dayWeek, traffic);
}
//------------------------------------------------------------Méthodes publiques
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
