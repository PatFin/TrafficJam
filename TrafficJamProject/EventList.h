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
// Role of class <EventList>
//
// The class EventList stores the Event instances as a simply linked list.
// New events are inserted at head.
//------------------------------------------------------------------------ 
using namespace std;
class EventList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
     void AddEvent(Event* aEvent);
    // Usage:
    //	This method will insert an event at the root of the list.
    //
    // Contract:
    //	Give a valid event (non null, and properly initialized) as a parameter.

     void DisplayList() const;
     // Usage:
     //	This method will display each event in the list (it won't display anything
     //	if the list is empty.
     //
     // Contract:
     // No contract.

     bool IsEmpty() const;
     // Usage:
     //	Returns true if the list is empty, false otherwise.
     //
     // Contract:
     //	No contract.

     Event* GetRoot() const;
     // Usage:
     //	Returns the root of the list.
     //
     // Contract:
     //	No contract.

     unsigned long int* GetTrafficNumbers();
     // Usage:
     //	Returns the traffic numbers array of the list.
     //
     // Contract:
     //	No contract.

     unsigned long int GetNbEvents() const;
     // Usage:
     // Returns the number of events listed in the event list.
     //
     // Contract:
     // No contract.

//------------------------------------------------- Surcharge d'opérateurs
    EventList & operator = ( const EventList & unEventList );
    // Usage:
    //
    // Contract:
    //


//-------------------------------------------- Constructeurs - destructeur
    EventList ( const EventList & aEventList );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contract:
    //

    EventList ( );
    // Usage:
    // Creates a default event list, only containing a root.
    //
    // Contract:
    // No contract.

    virtual ~EventList ( );
    // Usage:
    //
    // Contract:
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

    Event* root; // root of the list, it is not the first event.

    unsigned long int nbEvents; // number of events in the list

    unsigned long int trafficNumbers[4]; /* each slot of the array contains
     	 	 	 	 	 	 	 	 	 	the number of events having one of
     	 	 	 	 	 	 	 	 	 	the 4 different states */

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

	while (cursor->HasNext())
	{
//		if (cursor != aEventList.root)
//		{
//			strm << *cursor << endl;
//		}

		strm << *cursor->GetNext() << endl;

		cursor = cursor->GetNext();
	}

	return strm;
} //----- Fin de operator <<

//----------------------------------------- Types dépendants de <EventList>

#endif // EVENTLIST_H_
