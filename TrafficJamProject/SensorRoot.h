//--------------------- Inteface de la classe SensorRoot (SensorRoot.h) ----------------------
#if ! defined (SensorRoot_H)
#define SensorRoot_H


//--------------------------------------------------------- Interfaces utilisées
#include "Sensor.h"
#include "SensorLeaf.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Role of class SensorRoot
//	This class allows for the manipulation of a Tree containing sensors. The goal
//	is to collect Events. The creation of the corresponding Sensor is handled
//	automatically.
//------------------------------------------------------------------------------

class SensorRoot
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	int GetSensor(long int id, Sensor*& sensor) const;
	// Usage:
	//	Allows the user to recursively look for a Sensor in the tree whose id
	//	matches that of the one given as first parameter. The address is stored
	//	in the pointer given as second parameter.
	//	The method will return 0 if the Sensor was found, 1 otherwise.
	// Contract:
	//	The pointer sensor given as parameter should not point towards an
	//	existing Sensor. Otherwise using this method might result in memory leak.

	Sensor ** GetAllSensors();
	// Usage:
	//	Allows to get all the sensors inside the tree. The sensors will be given
	//	as an array of pointers of size that of the number of leaves in the tree.

	SensorLeaf* GetRoot()const ;

	int GetNbSensors() const;

	void InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,
			unsigned int day,unsigned int hour, unsigned int minute,
			unsigned int dayWeek, char traffic);
	// Usage:
	// 	Allows to add a new Event into the tree.
	// Contract:
	//	No contract.

	void Display();
	// Usage:
	//	Displays the tree.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	SensorRoot ();
	// Usage:
	//	Constructor.
	// Contract:
	//	No contract.
	
	virtual ~SensorRoot();
	// Usage:
	//	Destrutor.
	// Constract:
	//	No contract.
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	//--------------------------------------------------------Attributs protégés

	SensorLeaf * root;
	/**
	 * The first leaf of the tree, the root.
	*/

	SensorLeaf * nextParent;
	/**
	 * The parent of the next Sensor if it is created.
	 */

	SensorLeaf * lastElement;
	/**
	 * The last SensorLeaf inserted into the tree.
	 */

	int nbElements;
	/*
	 * The number of elements inside the tree.
	 */
};

//----------------------------------Autres définitions dépendantes de SensorRoot

#endif // ! defined (SensorRoot_H)
