/// Fichero de definición de la clase Nivel.
/** \file Nivel.cpp
 */

#include "Nivel.h"
#include <iostream>

using namespace std;

// Constructor por defecto.
Nivel::Nivel()
{

}

/// Destructor por defecto.
Nivel::~Nivel()
{

}

// Obtiene el identificador del nivel.
int Nivel::getIdentificador() const
{
	return identificador;
}

// Establece el identificador del nivel.
void Nivel::setIdentificador(int identificador)
{
	this->identificador = identificador;
}

// Obtiene el nombre del nivel.
string Nivel::getNombre() const
{
	return nombre;
}

// Establece el nombre del nivel.
void Nivel::setNombre(string nombre)
{
	this->nombre = nombre;
}

// Obtiene la dificultad del nivel.
int Nivel::getDificultad() const
{
	return dificultad;
}

// Establece la dificultad del nivel.
void Nivel::setDificultad(int dificultad)
{
	this->dificultad = dificultad;
}

// Obtiene la pantalla inicial.
Pantalla* Nivel::getPantallaInicial() const
{
	return pantallaInicial;
}

// Establece la pantalla inicial.
void Nivel::setPantallaInicial(Pantalla* pantallaInicial)
{
	this->pantallaInicial = pantallaInicial;
}

// Obtiene la pantalla final.
Pantalla* Nivel::getPantallaFinal() const
{
	return pantallaFinal;
}

// Establece la pantalla final.
void Nivel::setPantallaFinal(Pantalla* pantallaFinal)
{
	this->pantallaFinal = pantallaFinal;
}

// Obtiene la pantalla actual.
Pantalla* Nivel::getPantallaActual() const
{
	return pantallaActual;
}

// Establece la pantalla actual.
void Nivel::setPantallaActual(Pantalla* pantallaActual)
{
	this->pantallaActual = pantallaActual;
}

// Obtiene las pantallas.
list<Pantalla*> Nivel::getPantallas() const
{
	return pantallas;
}

// Establece las pantallas.
void Nivel::setPantallas(list<Pantalla*> pantallas)
{
	this->pantallas = pantallas;
}

// Obtiene la Pantalla a través de un id.
Pantalla* Nivel::getPantalla(int idPantalla) const
{
	return pantallaInicial;
}

// Establece la pantalla a través de un id.
void Nivel::setPantalla(int idPantalla, Pantalla* pantalla)
{
	
}





// Obtiene la información del nivel.
bool Nivel::obtener(int identificador)
{
	//InterfazINF::getInstancia()->obtenerNivel(identificador);
}

// Actualiza la información del nivel.
bool Nivel::actualizar() const
{
	//InterfazINF::getInstancia()->actualizarNivel(identificador, this);
}
