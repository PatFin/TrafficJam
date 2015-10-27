/*************************************************************************
                           Event  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Réalisation de la classe <Event> (fichier Event.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Event.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Event* Event::GetNext()
// Algorithme :
//
{
	return next;
} //----- Fin de Méthode

char Event::GetState()
// Algorithme :
//
{
	return trafficState;
} //----- Fin de Méthode

void Event::SetNext(Event * aEvent)
// Algorithme :
//
{
	next = aEvent;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
//Event::Event ( const Event & unEvent )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Event>" << endl;
//#endif
//} //----- Fin de Event (constructeur de copie)


Event::Event ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Event>" << endl;
#endif

    year = 0;
    month = 0;
    day = 0;
    trafficState = 'V';

    next = NULL;
} //----- Fin de Event

Event::Event (unsigned int aYear, unsigned int aMonth, unsigned int aDay,
			  char aState)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Event>" << endl;
#endif

    year = aYear;
    month = aMonth;
    day = aDay;
    trafficState = aState;

    next = NULL;
} //----- Fin de Event


Event::~Event ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Event>" << endl;
#endif
} //----- Fin de ~Event


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
