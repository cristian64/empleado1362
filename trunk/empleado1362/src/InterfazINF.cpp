/// Fichero de definición de la clase InterfazINF.
/** \file InterfazINF.cpp
 */

#include "InterfazINF.h"
#include <iostream>

using namespace std;

InterfazINF* InterfazINF::instancia = NULL;

// Constructor por defecto.
InterfazINF::InterfazINF()
{
	
}

// Destructor por defecto.
InterfazINF::~InterfazINF()
{
	// Liberamos la memoria.
}

// Devuelve la instancia de la clase singleton.
InterfazINF* InterfazINF::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazINF();
	return instancia;
}

// Inicia la interfaz.
void InterfazINF::iniciar()
{

}
