//--------------------- Réalistation de la classe SensorLeaf (SensorLeaf.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
//-------------------------------------------------------------Include personnel
#include "SensorLeaf.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques
void SensorLeaf::InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,unsigned int day,unsigned int hour, unsigned int minute, unsigned int dayWeek, unsigned int traffic)
// Algorithme :
//	We first look for a sensor in the tree whose id matches that of the one given
//	as parameter.
//	If found, then the event is added using method AddEvent of Sensor.
//	If not, a new Sensor is created and inserted into the tree. Then the
//	event is added to the Sensor.
{
	Sensor * sensor;
	if (GetSensor(idSensor, &sensor) == 1)
	{
		insertSensor(idSensor);
	}

	sensor->AddEvent(year,month,day,hour, minute, dayWeek, traffic);
}

int SensorLeaf::GetSensor(int idSensor, Sensor ** sensor)
{
	return 0;
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur

//---------------------------------------------------------------------PROTECTED
void SensorLeaf::insertSensor(long int idSensor)
// Algorithm:
//	A new Sensor is created as well as a new SensorLeaf. The lot is placed at the
//	end of the tree.
//	Then, as long as the parents Sensor's id is smaller than the child, the sensors
//	are flipped. This ensures that the tree remains in a HEAP situation.
{

}
//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
