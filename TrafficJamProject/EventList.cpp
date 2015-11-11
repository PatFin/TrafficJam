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
	if (root->HasNext())
	{
		aEvent->SetNext(root->GetNext());
		root->SetNext(aEvent);
	}
	else
	{
		root->SetNext(aEvent);
		aEvent->SetNext(aEvent);
	}

	switch (aEvent->GetState())
	{
	case 'V' :
		trafficNumbers[0]++;
		break;

	case 'J' :
		trafficNumbers[1]++;
		break;

	case 'R' :
		trafficNumbers[2]++;
		break;

	case 'N' :
		trafficNumbers[3]++;
		break;
	}

	nbEvents++;

} //----- Fin de Méthode

void EventList::DisplayList() const
// Algorithme :
//
{
	Event* cursor = root;

	while (cursor->HasNext())
	{
		if (cursor != root)
		{
			cout << *cursor << endl;
		}

		cursor = cursor->GetNext();
	}
} //----- Fin de Méthode

bool EventList::IsEmpty() const
// Algorithme :
//
{
	if (!root->HasNext())
	{
		return true;
	}
	else
	{
		return false;
	}

} //----- Fin de Méthode

Event* EventList::GetRoot() const
// Algorithme :
//
{
	return root;

} //----- Fin de Méthode

unsigned long int EventList::GetNbEvents() const
// Algorithme :
//
{
	return nbEvents;
} //----- Fin de Méthode

unsigned long int* EventList::GetTrafficNumbers()
// Algorithme :
//
{
	return trafficNumbers;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//EventList & EventList::operator = ( const EventList & unEventList )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EventList::EventList ( const EventList & aEventList )
// Algorithme :
//
{
#ifdef MAPD
    cout << "Appel au constructeur de copie de <EventList>" << endl;
#endif

    root = aEventList.GetRoot();
    nbEvents = 0;

} //----- Fin de EventList (constructeur de copie)


EventList::EventList ()
// Algorithme :
//
{
#ifdef MAPD
    cout << "Appel au constructeur de <EventList>" << endl;
#endif

    root = new Event();
    trafficNumbers = new unsigned long int[4];

    int i;

    for (i = 0; i < 4; i++)
    {
    	trafficNumbers[i] = 0;
    }

    nbEvents = 0;
} //----- Fin de EventList


EventList::~EventList ( )
// Algorithme :
//
{
#ifdef MAPD
    cout << "Appel au destructeur de <EventList>" << endl;
#endif

    delete root;
    delete[] trafficNumbers;
} //----- Fin de ~EventList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
