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
	
	virtual ~SensorLeaf ();
	// Usage:
	//	Destroys the current SensorLeaf and all its attributes, in particular it's
	//	Sensor.
	//	Beware! All the SensorLeaf that are the children of the current leaf will
	//	be destroyed in a recursive way.
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	void insertSensor (long int idSensor);
	// Usage:
	//	Allows to create a new instance of Sensor and place it into the tree.
	//	The tree is then modified to make it a HEAP back.
	// Contract:
	//	The tree shouldn't contain any Sensor whose Id is isSensor. Finding a
	//	specific Sensor will then fail (only part of the sensor's events would
	//	be retrieved).

	bool hasLeftChild ();
	// Usage:
	//	Allows to know if a Leaf has a left child or not.
	// Contract:
	//	No contract.

	bool hasRightChild ();
	// Usage:
	//	Allows to know if a Leaf has a right child or not.
	// Contract:
	//	No contract.

	void sortTree (Sensor * sensors, int left, int right);
	// Usage:
	//	This method is meant to be used upon insertion of a new Sensor. It sorts
	//	the sensors according to their Ids and puts them back into the tree so
	//	that the tree is a HEAP again.
	// Contract:
	//	No contract.

	Sensor * getAllSensors();
	// Usage:
	//	Allows for the gathering of all the Sensors adresses in a table.
	// Contract:
	//	To work properly, this method needs to ba applied to the root element of
	//	the tree.

	Sensor* refillTree(Sensor * sensorTable, SensorLeaf * leaf);
	// Usage;
	//	Refills the tree in a recursive way. sensors points towards the next element
	//	in a table of Sensors to fill the tree. index
	//--------------------------------------------------------Attributs protégés
	SensorLeaf * left;
	SensorLeaf * right;
	SensorLeaf * parent;
	SensorLeaf * childLeft;
	SensorLeaf * childRight;
	Sensor * sensor;
	SensorLeaf ** nextParent;
	SensorLeaf ** lastElement;
	int * nbLeaves;
};

//-----------------------------------------Autres définitions dépendantes de SensorLeaf

#endif // ! defined (SensorLeaf_H)
