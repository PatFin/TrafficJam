/*************************************************************************
                           Event  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Interface de la classe <Event> (fichier Event.h) ------
#if ! defined ( EVENT_H_ )
#define EVENT_H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Event>
//
//
//------------------------------------------------------------------------ 

class Event
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Event* GetNext();
    // Mode d'emploi :
    //
    // Contrat :
    //

    char GetState();
        // Mode d'emploi :
        //
        // Contrat :
        //

    void SetNext(Event * event);
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Event ( const Event & unEvent );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Event ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Event (unsigned int aYear, unsigned int aMonth, unsigned int aDay,
    			  char aState);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Event ( );
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

    unsigned int year;
    unsigned int month;
    unsigned int day;
    char trafficState;

    Event *next;


//---------------------------------------------------------- Classes amies

friend std::ostream& operator << ( std::ostream &strm, const Event & unEvent );

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

inline std::ostream& operator << ( std::ostream &strm, const Event & aEvent )
// Algorithme :
//
{
	return strm << aEvent.day << "/" << aEvent.month << "/" << aEvent.year
				<< " : " << aEvent.trafficState;
} //----- Fin de operator <<

//----------------------------------------- Types dépendants de <Event>

#endif // EVENT_H_
