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

#include "Event.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <EventList>
//
//
//------------------------------------------------------------------------ 

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

     void DisplayList();
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
    EventList ( const EventList & unEventList );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <EventList>

#endif // EVENTLIST_H_
