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
SensorLeaf::SensorLeaf (Sensor * const aSensor, SensorLeaf * aLeft, SensorLeaf * aParent)
{
	sensor = aSensor;
	right = this;
	childLeft = this;
	childRight = this;

	left = aLeft;
	aLeft->right = this;

	//The last element of the tree is now this. Using the double pointer, all
	//the elements of the tree are modified.
	this->lastElement = parent->lastElement;
	*lastElement = this;

	parent = aParent;
	if(parent->hasLeftChild())
	{
		parent->childRight = this;
		*nextParent = parent->right;
	}
	else
	{
		parent->childLeft = this;
	}
	nextParent = parent->nextParent;
}

//---------------------------------------------------------------------PROTECTED
void SensorLeaf::insertSensor(long int idSensor)
// Algorithm:
//	A new Sensor is created as well as a new SensorLeaf. The lot is placed at the
//	end of the tree.
//	Then tree is sorted and the different Sensors are reassigned to a leaf.
{
	Sensor * sensor = new Sensor(idSensor);
	SensorLeaf * leaf = new SensorLeaf(sensor, *lastElement, *nextParent);


}

bool SensorLeaf::hasLeftChild()
// Algorithm:
//	By default, upon creation, the children of the leaf point towards itself.
//	That's how the existence of a child is detected.
{
	return childLeft == this;
}
//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
