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
int SensorRoot::GetSensor(long int id, Sensor ** sensor)
// Algorithm:
//	See method GetSensor in SensorLEaf.
{
	return root->GetSensor(id, sensor);
}

void SensorRoot::InsertSensorValue (long int idSensor,unsigned int year,
		unsigned int month,	unsigned int day,unsigned int hour,
		unsigned int minute, unsigned int dayWeek, unsigned int traffic)
// Algorithm:
//	See method InsertSensorValue in SensorLeaf.
{
	root->InsertSensorValue(idSensor, year, month, day, hour, minute,
			dayWeek, traffic);
}
//--------------------------------------------------------Surcharge d'opérateurs
//---------------------------------------------------Constructeurs - Destructeur
SensorRoot::SensorRoot()
{
	root = new SensorLeaf(nbElements, &nextParent, &lastElement);
}

SensorRoot::~SensorRoot()
{
	delete(root); //The nextParent and lastElement are in the tree hence they will
				//be deleted as well.
}
//---------------------------------------------------------------------PROTECTED

//-------------------------------------------------------------------------PRIVE

//------------------------------------------------------------Méthodes protégées
