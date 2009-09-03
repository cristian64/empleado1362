/// Fichero de definición de la clase Nivel.
/** \file Nivel.cpp
 */

#include "Nivel.h"
#include <iostream>

using namespace std;

// Constructor por defecto.
Nivel()
{

}

/// Destructor por defecto.
~Nivel()
{

}

// Obtiene el identificador del nivel.
int getIdentificador()
{
	return identificador;
}

// Establece el identificador del nivel.
void setIdentificador(int identificador)
{
	this->identificador = identificador;
}

// Obtiene el nombre del nivel.
string getNombre()
{
	return nombre;
}

// Establece el nombre del nivel.
void setNombre(string nombre)
{
	this->nombre = nombre;
}

// Obtiene la dificultad del nivel.
int getDificultad()
{
	return dificultad;
}

// Establece la dificultad del nivel.
void setDificultad(int dificultad)
{
	this->dificultad = dificultad;
}

// Obtiene la coordenada2D de la pantalla inicial.
Coordenada2D getPantallaInicial()
{
	return pantallaInicial;
}

// Establece la coordenada2D de la pantalla inicial.
void setPantallaInicial(Coordenada2D pantallaInicial)
{
	this->pantallaInicial = pantallaInicial;
}

// Obtiene la coordenada2D de la pantalla final.
Coordenada2D getPantallaFinal()
{
	return pantallaFinal;
}

// Establece la coordenada2D de la pantalla final.
void setPantallaFinal(Coordenada2D pantallaFinal)
{
	this->pantallaFinal = pantallaFinal;
}

// Obtiene la coordenada2D de la pantalla actual.
Coordenada2D getPantallaActual()
{
	return pantallaActual;
}

// Establece la coordenada2D de la pantalla actual.
void setPantallaActual(Coordenada2D pantallaActual)
{
	this->pantallaActual = pantallaActual;
}

// Obtiene la Pantalla a través de una Coordenada2D.
Pantalla getPantalla(Coordenada2D coordenada)
{
	return getPantalla(coordenada.getX(), coordenada.getY());
}

// Obtiene la Pantalla indicando la coordenada.
Pantalla getPantalla(int x, int y)
{
	return pantallas[x][y];
}

// Establece la pantalla a través de una Coordenada2D.
void setPantalla(Coordenada2D coordenada, Pantalla pantalla)
{
	setPantalla(coordenada.getX(), coordenada.getY(), pantalla);
}

/// Establece la pantalla indicando la coordenada.
void setPantalla(int x, int y, Pantalla pantalla)
{
	pantallas[x][y] = pantalla;
}

// Obtiene la información del nivel.
bool obtener(int identificador)
{
	InterfazINF::getInstancia()->obtenerNivel(identificador);
}

// Actualiza la información del nivel.
bool actualizar()
{
	InterfazINF::getInstancia()->actualizarNivel(identificador, this);
}
