#include "InterfazSND.h"
#include <iostream>

using namespace std;

InterfazSND* InterfazSND::instancia = NULL;

// Constructor por defecto.
InterfazSND::InterfazSND()
{
	
}

// Destructor por defecto.
InterfazSND::~InterfazSND()
{
	// Liberamos la memoria.
}

// Devuelve la instancia de la clase singleton.
InterfazSND* InterfazSND::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazSND();
	return instancia;
}

// Inicia la interfaz.
void InterfazSND::iniciar()
{

}
