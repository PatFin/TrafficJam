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
// Role of class <Event>
//
//
//------------------------------------------------------------------------ 

class Event
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Event* GetNext();
    // Usage:
    //	Returns the next element.
    //	If the selected element is the latest of the EventList, the method will
    //	return the same element
    //
    // Contract:
    //	No contract.

    char GetState();
    // Usage:
    //	Returns the traffic state of the event.
    //
    // Contract:
    //	No contract.

    void SetNext(Event * event);
    // Usage:
    //	Sets the next of the considered element with the one given as a
    //	parameter.
    //
    // Contract:
    //	The event given as a parameter must be valid.

    bool HasNext();
    // Usage:
    //	Returns true if the element has a next (other than itslef), false
    //	otherwise.
    //
    // Contract:
    //	No contract.
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Event ( const Event & unEvent );
    // Usage(copy constructor):
    //
    // Contract:
    //

    Event ();
    // Usage:
    //	Default event constructor. Sets the next to the element itself.
    //	Sets 'V' to the traffic state of the event, 0 to all the other attributes.
    //
    // Contract:
    //	No contract.

    Event (unsigned int aYear, unsigned int aMonth, unsigned int aDay,
    			  char aState);
    // Usage:
    //	This constructor will set the attributes of the event with those given as
    //	parameters.
    //	It sets the next of the event to the same event.
    //
    // Contract:
    //	The parameters must be valid (right type and right order).
    //	aState must be 'V', 'J', 'R' or 'N'.

    virtual ~Event ( );
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

    unsigned int year;
    unsigned int month;
    unsigned int day;
    char trafficState;

    Event *next; // next event in the EventList


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
