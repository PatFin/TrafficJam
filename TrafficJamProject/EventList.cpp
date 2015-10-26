/*************************************************************************
                           EventList  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Réalisation de la classe <EventList> (fichier EventList.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EventList.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void EventList::AddEvent(Event* aEvent)
// Algorithme :
//
{
	if (root->GetNext() != NULL)
	{
		aEvent->GetNext() = &(root->GetNext());
		root->GetNext() = &aEvent;
	}
	else
	{
		root->GetNext() = &aEvent;
		aEvent->GetNext() = NULL;
	}

} //----- Fin de Méthode

void EventList::DisplayList()
// Algorithme :
//
{
	Event* cursor = root;

	while (cursor != NULL)
	{
		cout << cursor << endl;

		cursor = &(cursor->GetNext());
	}
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//EventList & EventList::operator = ( const EventList & unEventList )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//EventList::EventList ( const EventList & unEventList )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <EventList>" << endl;
//#endif
//} //----- Fin de EventList (constructeur de copie)


EventList::EventList ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EventList>" << endl;
#endif

    root = new Event();
} //----- Fin de EventList


EventList::~EventList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EventList>" << endl;
#endif
} //----- Fin de ~EventList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées