/// Fichero de definición de la clase InterfazPSX.
/** \file InterfazPSX.cpp
 */

#include "InterfazPSX.h"
#include <iostream>

using namespace std;

InterfazPSX* InterfazPSX::instancia = NULL;

// Constructor por defecto.
InterfazPSX::InterfazPSX()
{
	
}

// Destructor por defecto.
InterfazPSX::~InterfazPSX()
{
	// Liberamos la memoria.
}

// Devuelve la instancia de la clase singleton.
InterfazPSX* InterfazPSX::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazPSX();
	return instancia;
}

// Inicia la interfaz.
void InterfazPSX::iniciar()
{

}
