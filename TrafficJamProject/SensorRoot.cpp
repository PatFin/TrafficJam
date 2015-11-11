//--------------------- Réalistation de la classe SensorRoot (SensorRoot.h) ------------------


//---------------------------------------------------------------------- INCLUDE

//---------------------------------------------------------------Include système
using namespace std;
#include <iostream>
//-------------------------------------------------------------Include personnel
#include "SensorRoot.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------PUBLIC

//------------------------------------------------------------Méthodes publiques
int SensorRoot::GetSensor(long int id, Sensor*& sensor) const
// Usage:
//	Allows for the gathering of all the Sensors adresses in a table.
//	The first argument should be a pointer on a table of size the number of
//	elements in the tree. The second should be the root leaf of the tree.
// Contract:
//	To work properly, this method needs to be applied to the root element of
//	the tree.
// Algorithm:
//	See method GetSensor in SensorLEaf.
{
	return root->GetSensor(id, sensor);
}

Sensor ** SensorRoot::GetAllSensors()
{
	Sensor ** sensors = new Sensor* [nbElements];
	root->GetAllSensors(sensors);
	return sensors;
}

SensorLeaf* SensorRoot::GetRoot() const
{
	return root;
}

int SensorRoot::GetNbSensors() const
// Algorithm:
//
{
	return nbElements;
}

void SensorRoot::InsertSensorValue (long int idSensor,unsigned int year,
		unsigned int month,	unsigned int day,unsigned int hour,
		unsigned int minute, unsigned int dayWeek, char traffic)
// Algorithm:
//	See method InsertSensorValue in SensorLeaf.
{
	root->InsertSensorValue(idSensor, year, month, day, hour, minute,
			dayWeek, traffic);
}

void SensorRoot::Display()
{
	root->Display();
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
SensorRoot::SensorRoot()
{
#ifdef MAP
	cout << "Construction SensorRoot" << endl;
#endif
	root = new SensorLeaf(&nbElements, &nextParent, &lastElement);
}

SensorRoot::~SensorRoot()
{

#ifdef MAP
	cout << "Destruction SensorRoot" << endl;
#endif
	delete(root); //The nextParent and lastElement are in the tree hence they will
				//be deleted as well.
}
//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
