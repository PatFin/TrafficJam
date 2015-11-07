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
void SensorLeaf::InsertSensorValue (long int idSensor,unsigned int year,
		unsigned int month,unsigned int day,unsigned int hour,
		unsigned int minute, unsigned int dayWeek, char traffic)
// Algorithm:
//	We first look for a sensor in the tree whose id matches that of the one given
//	as parameter.
//	If found, then the event is added using method AddEvent of Sensor.
//	If not, a new Sensor is created and inserted into the tree. Then the
//	event is added to the Sensor.
{
	Sensor * sensor;
	if (*nbLeaves > 0)
	{
		//If the sensor is not found we create it and add it to the tree.
		if (GetSensor(idSensor, &sensor) == 1)
		{

			sensor = insertSensor(idSensor);

			//Specific case when adding the second leaf to the tree.
			if (*nbLeaves == 2)
			{
				right = childLeft;
			}
		}
	}
	else
	{
		//Specific empty tree case.
		sensor = new Sensor(idSensor);
		this->sensor = sensor;
		*nbLeaves = 1;
	}
	sensor->AddEvent(year,month,day,hour, minute, dayWeek, traffic);

	cout << "The event " << year << "/" << month << "/" << day << " " << hour
		 << "h" << minute << ", day " << dayWeek << " : " << traffic
		 << " has been added to sensor " << idSensor << "." << endl;
}

int SensorLeaf::GetSensor(const long int idSensor, Sensor** result)
{
	SensorLeaf * leaf;
	if (getSensorLeaf(idSensor, &leaf) == 0)
	{
		*result = leaf->sensor;
		return 0;
	}
	else
	{
		return 1;
	}
}

void SensorLeaf::Display()
{
	cout << sensor->GetId() << endl;
	cout << sensor << endl;
	if(hasLeftChild())
	{
		childLeft->Display();
	}
	if(hasRightChild())
	{
		childRight->Display();
	}
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
SensorLeaf::SensorLeaf(int * numberLeaves, SensorLeaf ** aParent,
		SensorLeaf ** alastLeaf)
{
	parent = this;
	left = this;
	right = this;
	childLeft = this;
	childRight = this;

	nbLeaves = numberLeaves;
	nextParent = aParent;
	lastElement = alastLeaf;

	*nbLeaves = 0;
	*nextParent = this;
	*lastElement = this;
}

SensorLeaf::SensorLeaf (Sensor * const aSensor, SensorLeaf * aLeft, SensorLeaf * aParent)
{
	sensor = aSensor;
	right = this;
	childLeft = this;
	childRight = this;

	left = aLeft;
	aLeft->right = this;

	//The last element of the tree is now 'this'. Using the double pointer, all
	//the elements of the tree are modified.
	parent = aParent;
	this->lastElement = parent->lastElement;
	*lastElement = this;

	nextParent = parent->nextParent;
	if(parent->hasLeftChild())
	{
		parent->childRight = this;
		*nextParent = parent->right;
	}
	else
	{
		parent->childLeft = this;
	}
	nbLeaves = parent->nbLeaves;
	*nbLeaves = *nbLeaves +1;
#ifdef MAP
	cout << "Using constructor 2 of <SensorLeaf>" << endl;
	cout << "*There are now " << *nbLeaves << " leaves in the tree" << endl;
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
Sensor * SensorLeaf::insertSensor(long int idSensor)
// Algorithm:
//	A new Sensor is created as well as a new SensorLeaf. The lot is placed at the
//	end of the tree.
//	Then tree is sorted and the different Sensors are reassigned to a leaf.
{
	//Creation
	Sensor * sensor = new Sensor(idSensor);
	new SensorLeaf(sensor, *lastElement, *nextParent);

	//Sorting
	sortTree();
	return sensor;
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

void SensorLeaf::sortTree()
// Algorithm:
//	The Sensors of the tree are gathered as a pointer table and then sorted in
//	this table. As all the elements but one are not ordered, only one passage
//	with the bubble sort algorithm starting from the end of the table is enough
//	The Tree sensors are then reassigned starting from the moved Sensor place..
{
	Sensor * sensor [*nbLeaves];
	GetAllSensors(sensor, this);

	cout << "Tableau avant tri" << endl;
	int a;
	for (a= 0;a<*nbLeaves; a++)
	{
		cout << sensor[a]->GetId()<< endl;
	}

	//Bubble sort starting from the end.
	int index = *nbLeaves -1;
	while (index > 0)
	{
		if (sensor[index -1]->GetId() < sensor[index]->GetId())
		{
			Sensor * buff = sensor[index];
			sensor[index] = sensor[index -1];
			sensor[index-1] = buff;
		}
		index --;
	}

	cout << "Tableau après tri" << endl;
	for (a= 0;a<*nbLeaves; a++)
	{
		cout << sensor[a]->GetId()<< endl;
	}


	refillTree(sensor, this);
}

Sensor ** SensorLeaf::refillTree(Sensor ** sensorTable, SensorLeaf* leaf)
// Algorithm:
//	Recursive algorithm which is going to fill the top left elements first.
{
	leaf->sensor = *sensorTable;
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

Sensor ** SensorLeaf::GetAllSensors(Sensor * sensorTable [], SensorLeaf * leaf)
// Algorithm:
//	We go through the whole tree going to the left elements first in a
//	recursive process. We gather all the pointers of all the Sensors contained.
{
	*sensorTable = leaf->sensor;
	sensorTable ++;

	if (leaf->hasLeftChild())
	{
		sensorTable = GetAllSensors(sensorTable, leaf->childLeft);
	}
	if (leaf->hasRightChild())
	{
		sensorTable = GetAllSensors(sensorTable, leaf->childRight);
	}

	return sensorTable;
}

int SensorLeaf::getSensorLeaf(int idSensor, SensorLeaf **result)
{
	int idLeaf = sensor->GetId();
	if (idLeaf == idSensor)
	{
		*result = this;
		return 0;
	}
	else
	{
		if (hasRightChild() && idSensor <= childRight->sensor->GetId())
		{
			return childRight->getSensorLeaf(idSensor, result);
		}
		else if (hasLeftChild() && idSensor <= childLeft->sensor->GetId())
		{
			return childLeft->getSensorLeaf(idSensor, result);
		}
		else
		{
			//It isn't possible to find the Sensor with the corresponding ID, we return 1.
			return 1;
		}
#ifdef MAP
		cout << "The Sensor n°:" << idSensor << " was not found" << endl;
#endif
		return 1;
	}
}
//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
