//--------------------- Inteface de la classe TreeSensor (TreeSensor.h) ----------------------
#if ! defined (TreeSensor_H)
#define TreeSensor_H


//--------------------------------------------------------- Interfaces utilisées
#include "TreeSensor.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe TreeSensor
// TreeSensor allows the gathering of multiple instances of the Sensor class to
// be stored in a tree. The tree will be balanced yet not perfect. The Sensors
// will be ordered according to their id number.
// The tree will follow the HEAP (highest element as parent) taking the Sensor ID
// as a reference.
//------------------------------------------------------------------------------

class TreeSensor
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	void InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,unsigned int day,unsigned int hour, unsigned int minute, unsigned int dayWeek, unsigned int traffic);
	// Mode d'emploi :
	// 	Allows to put a new Event in the tree.
	// Contrat :
	//	No contract.
	int GetSensor (int idSensor, Sensor ** sensor);
	// Mode d'emploi
	//	Allows to get a Sensor specified by its id. The pointer sensor given as
	//	parameter will point towards the Sensor.
	//	The method will return 0 if the Sensor whose id is idSensor was found,
	//	1 otherwise. Beware of segmentation faults in this case.
	// Contrat :
	//	sensor shouldn't have been initialized. If not the case, using this method
	//	will result in memory leaks.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	void insertSensor (long int idSensor);
	// Mode d'emploi :
	//	Allows to create a new instance of Sensor and place it into the tree.
	//	The tree is then modified to make it a HEAP back.
	// Contrat :
	//	The tree shouldn't contain any Sensor whose Id is isSensor. Finding a
	//	specific Sensor will then fail (only part of the sensor's events would
	//	be retrieved).
	//--------------------------------------------------------Attributs protégés
	TreeSensor * left;
	TreeSensor * right;
	TreeSensor * parent;
	TreeSensor * childLeft;
	TreeSensor * childRight;
	Sensor * sensor;
};

//-----------------------------------------Autres définitions dépendantes de TreeSensor

#endif // ! defined (TreeSensor_H)
