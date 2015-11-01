/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ------
#if ! defined ( SENSOR_H_ )
#define SENSOR_H_

//--------------------------------------------------- Interfaces utilisées
#include "EventList.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------ 

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	long int GetId() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	EventList* GetEvents(unsigned int d, unsigned int h, unsigned int m) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

    void AddEvent(unsigned int year, unsigned int month, unsigned int day,
    			  unsigned int hour, unsigned int minute, unsigned int d7,
				  unsigned int trafficState);
    // Mode d'emploi :
    //
    // Contrat :
    //

    float* GetAverageTrafficMinute(unsigned int d7, unsigned int h,
    		unsigned int m) const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor (long aId);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    long int id;

    EventList* events[7][24][60];

//---------------------------------------------------------- Classes amies

friend std::ostream& operator << (std::ostream &strm, const Sensor & aSensor);

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

inline std::ostream& operator << (std::ostream &strm, const Sensor & aSensor)
// Algorithme :
//
{
	int i, j, k;

	strm << "Sensor " << aSensor.id << " : " << endl << endl;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 24; j++)
		{
			for (k = 0; k < 60; k++)
			{
				if (!aSensor.events[i][j][k]->IsEmpty())
				{
					strm << "day " << i+1 << ", " << j << "h" << k << " : "
						 << endl << *(aSensor.events[i][j][k]) << endl;
				}
			}
		}
	}

	return strm;
} //----- Fin de operator <<

//----------------------------------------- Types dépendants de <Sensor>

#endif // SENSOR_H_
