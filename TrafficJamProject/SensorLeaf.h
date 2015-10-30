//--------------------- Inteface de la classe SensorLeaf (SensorLeaf.h) ----------------------
#if ! defined (SensorLeaf_H)
#define SensorLeaf_H


//--------------------------------------------------------- Interfaces utilisées
#include "Sensor.h"
#include "SensorLeaf.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe SensorLeaf
// SensorLeaf allows the gathering of multiple instances of the Sensor class to
// be stored in a tree. The tree will be balanced yet not perfect. The Sensors
// will be ordered according to their id number.
// The tree will follow the HEAP (highest element as parent) taking the Sensor ID
// as a reference.
//------------------------------------------------------------------------------

class SensorLeaf
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	void InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,unsigned int day,unsigned int hour, unsigned int minute, unsigned int dayWeek, unsigned int traffic);
	// Usage:
	// 	Allows to put a new Event in the tree.
	// Contract:
	//	No contract.
	int GetSensor (int idSensor, Sensor ** sensor);
	// Usage
	//	Allows to get a Sensor specified by its id. The pointer sensor given as
	//	parameter will point towards the Sensor.
	//	The method will return 0 if the Sensor whose id is idSensor was found,
	//	1 otherwise. Beware of segmentation faults in this case.
	// Contract :
	//	sensor shouldn't have been initialized. If not the case, using this method
	//	will result in memory leaks.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur

	SensorLeaf (Sensor * const aSensor, SensorLeaf * aLeft, SensorLeaf * aParent);
	// Usage:
	//	Allows to create a new SensorLeaf with an initial sensor. The sensor isn't
	//	modified in this method.
	// Contract:
	//	No contract.
	
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	void insertSensor (long int idSensor);
	// Usage :
	//	Allows to create a new instance of Sensor and place it into the tree.
	//	The tree is then modified to make it a HEAP back.
	// Contract :
	//	The tree shouldn't contain any Sensor whose Id is isSensor. Finding a
	//	specific Sensor will then fail (only part of the sensor's events would
	//	be retrieved).

	bool hasLeftChild ();
	// Usage:
	//	Allows to know if a Leaf has a left child or not.
	// Contract;
	//	No contract.
	//--------------------------------------------------------Attributs protégés
	SensorLeaf * left;
	SensorLeaf * right;
	SensorLeaf * parent;
	SensorLeaf * childLeft;
	SensorLeaf * childRight;
	Sensor * sensor;
	SensorLeaf ** nextParent;
	SensorLeaf ** lastElement;
};

//-----------------------------------------Autres définitions dépendantes de SensorLeaf

#endif // ! defined (SensorLeaf_H)
