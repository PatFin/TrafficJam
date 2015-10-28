//--------------------- Inteface de la classe TreeSensor (TreeSensor.h) ----------------------
#if ! defined (TreeSensor_H)
#define TreeSensor_H


//--------------------------------------------------------- Interfaces utilisées
#include "TreeSensor.h"
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe TreeSensor
// TreeSensor allow the gathering of multiple instances of the Sensor class to
// be stored in a tree. The tree will be balanced yet not perfect. The Sensors
// will be ordered according to their id number.
//------------------------------------------------------------------------------

class TreeSensor
{
	//--------------------------------------------------------------------PUBLIC
	public : 
	//--------------------------------------------------------Méthodes publiques
	//----------------------------------------------------Surcharge d'opérateurs
	//-----------------------------------------------Constructeurs - Destructeur
	
	//---------------------------------------------------------------------PRIVE
	protected :
	//--------------------------------------------------------Méthodes protégées
	//--------------------------------------------------------Attributs protégés
	TreeSensor * left;
	TreeSensor * right;
	TreeSensor * top;
	Sensor * sensor;
};

//-----------------------------------------Autres définitions dépendantes de TreeSensor

#endif // ! defined (TreeSensor_H)
