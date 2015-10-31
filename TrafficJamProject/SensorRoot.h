//--------------------- Inteface de la SensorRoot xxx (SensorRoot.h) ----------------------
#if ! defined (SensorRoot_H)
#define SensorRoot_H


//--------------------------------------------------------- Interfaces utilisées
#include "Sensor.h"
#include "SensorLeaf.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la SensorRoot SensorRoot
// TODO
//------------------------------------------------------------------------------

class SensorRoot
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	int GetSensor(long int id, Sensor ** sensor);
	// Usage:
	//	Allows the user to get the pointer on a sensor in the tree whose id
	//	matches that of the one given as parameter. The adress is stored in the
	//	pointer given as second parameter.
	//	The method will return 0 if the Sensor was found, 1 otherwise.
	// Contract:
	//	The pointer sensor given as parameter should not point towards an
	//	existing Sensor. Otherwise, using this method might result in memory leak.

	void InsertSensorValue (long int idSensor,unsigned int year,unsigned int month,unsigned int day,unsigned int hour, unsigned int minute, unsigned int dayWeek, unsigned int traffic);
	// Usage:
	// 	Allows to add a new Event into the tree.
	// Contract:
	//	No contract.
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	//--------------------------------------------------------Attributs protégés
	/**
	 * The first leaf of the tree, the root.
	 */
	SensorLeaf * root;
	/**
	 * The parent of the next Sensor if it is created.
	 */
	SensorLeaf * nextParent;
	/**
	 * The last SensorLeaf inserted into the tree.
	 */
	SensorLeaf * lastElement;
	/*
	 * The number of elements inside the tree.
	 */
	int nbElements;
};

//----------------------------------Autres définitions dépendantes de SensorRoot

#endif // ! defined (SensorRoot_H)
