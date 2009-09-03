/// Fichero de definición de la clase InterfazIA.
/** \file InterfazIA.cpp
 */

#include "InterfazIA.h"
#include <iostream>

using namespace std;

InterfazIA* InterfazIA::instancia = NULL;

// Constructor por defecto.
InterfazIA::InterfazIA()
{
	
}

// Destructor por defecto.
InterfazIA::~InterfazIA()
{
	// Liberamos la memoria.
}

// Devuelve la instancia de la clase singleton.
InterfazIA* InterfazIA::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazIA();
	return instancia;
}

// Inicia la interfaz.
void InterfazIA::iniciar()
{

}
