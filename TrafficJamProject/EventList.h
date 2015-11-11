/*************************************************************************
                           EventList  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Interface de la classe <EventList> (fichier EventList.h) ------
#if ! defined ( EVENTLIST_H_ )
#define EVENTLIST_H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "Event.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <EventList>
//
//
//------------------------------------------------------------------------ 
using namespace std;
class EventList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
     void AddEvent(Event* aEvent);
    // Mode d'emploi :
    //
    // Contrat :
    //

     void DisplayList() const;
     // Mode d'emploi :
     //
     // Contrat :
     //

     bool IsEmpty() const;
     // Mode d'emploi :
     //
     // Contrat :
     //

     Event* GetRoot() const;
     // Mode d'emploi :
     //
     // Contrat :
     //

     unsigned long int* GetTrafficNumbers();
     // Mode d'emploi :
     //
     // Contrat :
     //

     unsigned long int GetNbEvents() const;
     // Mode d'emploi :
     //
     // Contrat :
     //

//------------------------------------------------- Surcharge d'opérateurs
    EventList & operator = ( const EventList & unEventList );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EventList ( const EventList & aEventList );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EventList ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EventList ( );
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

    Event* root;
    unsigned long int nbEvents;
    unsigned long int* trafficNumbers;

//---------------------------------------------------------- Classes amies

friend std::ostream& operator << (std::ostream &strm, const EventList & aEventList);

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

inline std::ostream& operator << (std::ostream &strm, const EventList & aEventList)
// Algorithme :
//
{
	Event* cursor = aEventList.root;

	while (cursor != NULL)
	{
		if (cursor != aEventList.root)
		{
			strm << *cursor << endl;
		}

		cursor = cursor->GetNext();
	}

	return strm;
} //----- Fin de operator <<

//----------------------------------------- Types dépendants de <EventList>

#endif // EVENTLIST_H_
