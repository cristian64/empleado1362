#include "Juego.h"
#include <iostream>

using namespace std;

/// Función principal
int main(int argc, char **argv)
{
	// Crea una instancia de la aplicación.
	Juego juego;

	try
	{
		juego.iniciar();
	}
	catch (Exception& e)
	{
		cerr << "Ocurrió una exceipción: " << e.what() << endl;
	}
}
