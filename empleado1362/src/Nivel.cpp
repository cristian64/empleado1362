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

// Obtiene la coordenada de la pantalla inicial.
Coordenada Nivel::getPantallaInicial() const
{
	return pantallaInicial;
}

// Establece la coordenada de la pantalla inicial.
void Nivel::setPantallaInicial(Coordenada pantallaInicial)
{
	this->pantallaInicial = pantallaInicial;
}

// Obtiene la coordenada de la pantalla final.
Coordenada Nivel::getPantallaFinal() const
{
	return pantallaFinal;
}

// Establece la coordenada de la pantalla final.
void Nivel::setPantallaFinal(Coordenada pantallaFinal)
{
	this->pantallaFinal = pantallaFinal;
}

// Obtiene la coordenada de la pantalla actual.
Coordenada Nivel::getPantallaActual() const
{
	return pantallaActual;
}

// Establece la coordenada de la pantalla actual.
void Nivel::setPantallaActual(Coordenada pantallaActual)
{
	this->pantallaActual = pantallaActual;
}

// Obtiene las pantallas.
Matriz<Pantalla> Nivel::getPantallas() const
{
	return pantallas;
}

// Establece las pantallas.
void Nivel::setPantallas(Matriz<Pantalla> pantallas)
{
	this->pantallas = pantallas;
}

// Obtiene la Pantalla a través de una Coordenada.
Pantalla Nivel::getPantalla(Coordenada coordenada) const
{
	return getPantalla(coordenada.getX(), coordenada.getY());
}

// Obtiene la Pantalla indicando la coordenada.
Pantalla Nivel::getPantalla(int x, int y) const
{
	return pantallas[x][y];
}

// Establece la pantalla a través de una Coordenada.
void Nivel::setPantalla(Coordenada coordenada, Pantalla pantalla)
{
	setPantalla(coordenada.getX(), coordenada.getY(), pantalla);
}

/// Establece la pantalla indicando la coordenada.
void Nivel::setPantalla(int x, int y, Pantalla pantalla)
{
	pantallas[x][y] = pantalla;
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
