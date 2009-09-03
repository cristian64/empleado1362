/// Fichero de definición de la clase Juego.
/** \file Juego.cpp
 */

#include "Juego.h"
#include <iostream>

using namespace std;

// Constructor por defecto.
Juego::Juego()
{
	// Obtenemos las interfaces.
	interfazGFX = InterfazGFX::getInstancia();
	interfazIA = InterfazIA::getInstancia();
	interfazPSX = InterfazPSX::getInstancia();
	interfazINF = InterfazINF::getInstancia();
	interfazSND = InterfazSND::getInstancia();
}

// Destructor por defecto.
Juego::~Juego()
{
	delete interfazGFX;
	delete interfazIA;
	delete interfazPSX;
	delete interfazINF;
	delete interfazSND;
}

// Inicia el juego.
void Juego::iniciar()
{
	// Iniciamos las interfaces.
	interfazGFX->iniciar();
	interfazIA->iniciar();
	interfazPSX->iniciar();
	interfazINF->iniciar();
	interfazSND->iniciar();
}
