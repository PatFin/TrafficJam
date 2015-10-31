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

	nbLeaves = parent->nbLeaves;
	*nbLeaves = *nbLeaves +1;
#ifdef MAP
	cout << "Using constructor of <SensorLeaf>" << endl;
	cout << "Il y a maintenant " << *nbLeaves << " leaves in the tree" << endl;
#endif
}

SensorLeaf::~SensorLeaf()
{
	if (hasLeftChild())
	{
		delete(childLeft);
	}
	if (hasRightChild())
	{
		delete(childRight);
	}


}

//---------------------------------------------------------------------PROTECTED
void SensorLeaf::insertSensor(long int idSensor)
// Algorithm:
//	A new Sensor is created as well as a new SensorLeaf. The lot is placed at the
//	end of the tree.
//	Then tree is sorted and the different Sensors are reassigned to a leaf.
{
	//Création
	Sensor * sensor = new Sensor(idSensor);
	new SensorLeaf(sensor, *lastElement, *nextParent);

	//Tri
	sortTree(getAllSensors(), 0, *nbLeaves);
}

bool SensorLeaf::hasLeftChild()
// Algorithm:
//	By default, upon creation, the children of the leaf point towards itself.
//	That's how the existence of a child is detected.
{
	return !(childLeft == this);
}

bool SensorLeaf::hasRightChild()
{
	return !(childRight == this);
}

void SensorLeaf::sortTree(Sensor * sensors, int left, int right)
// Algorithm:
//	The Sensors of the tree are gathered as a pointer table and then sorted in
//	this table following the quicksort algorithm. The Tree sensors are then
//	reassigned according to this new sort.
{


}

Sensor * SensorLeaf::refillTree(Sensor * sensorTable, SensorLeaf* leaf)
// Algorithm:
//	Recursive algorithm which is going to fill the top and left elements first.
{
	leaf->sensor = sensorTable;
	sensorTable++;

	if (leaf->hasLeftChild())
	{
		sensorTable = refillTree(sensorTable, leaf->childLeft);
	}
	if (leaf->hasRightChild())
	{
		sensorTable = refillTree(sensorTable, leaf->childRight);
	}

	return sensorTable;
}

Sensor * SensorLeaf::getAllSensors()
// Algorithm:
//	We create a table of size the number of Sensors in the tree. We then go
//	through the whole tree and gather all the pointers.
{
	Sensor * sensorTable [*nbLeaves];
	SensorLeaf * currentLeaf = this;
	int n = 0;
	while (n < *nbLeaves)
	{
		sensorTable[n++] = currentLeaf->sensor;
	}

	return *sensorTable;
}
//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
