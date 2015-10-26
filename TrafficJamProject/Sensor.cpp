/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : Oct 22, 2015
    copyright            : (C) 2015 par B3104
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Sensor::AddEvent(unsigned int year, unsigned int month, unsigned int day,
    			  unsigned int hour, unsigned int minute, unsigned int d7,
				  unsigned int state)
// Algorithme :
//
	{
		events[d7-1][hour][minute]->AddEvent(new Event(year, month, day, state));
	} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Sensor & Sensor::operator = ( const Sensor & unSensor )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Sensor>" << endl;
//#endif
//} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ()
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au constructeur par défaut de <Sensor>" << endl;
	#endif

    id = 0;

    int i, j, k;

    for (i = 0; i < 7; i++)
    {
    	for (j = 0; j < 24; j++)
    	{
    		for (k = 0; k < 60; k++)
    		{
    			events[i][j][k] = new EventList();
    		}
    	}
    }
} //----- Fin de Sensor

Sensor::Sensor (long int aId)
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur de <Sensor>" << endl;
	#endif

    id = aId;

    int i, j, k;

    for (i = 0; i < 7; i++)
    {
       	for (j = 0; j < 24; j++)
       	{
       		for (k = 0; k < 60; k++)
       		{
       			events[i][j][k] = new EventList();
       		}
       	}
    }
} //----- Fin de Sensor


Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
