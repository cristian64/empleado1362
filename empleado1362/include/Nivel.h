/// Fichero de cabecera de la clase Nivel.
/** \file Nivel.h
 */

#ifndef _NIVEL_H
#define	_NIVEL_H


#include "Pantalla.h"
#include "Coordenada2D.h"
#include "InterfazINF.h"
#include <iostream>

using namespace std;


/** Nivel
*/
class Nivel
{
	public:
		/// Constructor por defecto.
		Nivel();

		/// Destructor por defecto.
		~Nivel();





		/// Obtiene el identificador del nivel.
		int getIdentificador();

		/// Establece el identificador del nivel.
		void setIdentificador(int identificador);

		/// Obtiene el nombre del nivel.
		string getNombre();

		/// Establece el nombre del nivel.
		void setNombre(string nombre);

		/// Obtiene la dificultad del nivel.
		int getDificultad();

		/// Establece la dificultad del nivel.
		void setDificultad(int dificultad);

		/// Obtiene la coordenada2D de la pantalla inicial.
		Coordenada2D getPantallaInicial();

		/// Establece la coordenada2D de la pantalla inicial.
		void setPantallaInicial(Coordenada2D pantallaInicial);

		/// Obtiene la coordenada2D de la pantalla final.
		Coordenada2D getPantallaFinal();

		/// Establece la coordenada2D de la pantalla final.
		void setPantallaFinal(Coordenada2D pantallaFinal);

		/// Obtiene la coordenada2D de la pantalla actual.
		Coordenada2D getPantallaActual();

		/// Establece la coordenada2D de la pantalla actual.
		void setPantallaActual(Coordenada2D pantallaActual);

		/// Obtiene la Pantalla a través de una Coordenada2D.
		Pantalla getPantalla(Coordenada2D coordenada);

		/// Obtiene la Pantalla indicando la coordenada.
		Pantalla getPantalla(int x, int y);

		/// Establece la pantalla a través de una Coordenada2D.
		void setPantalla(Coordenada2D coordenada, Pantalla pantalla);

		/// Establece la pantalla indicando la coordenada.
		void setPantalla(int x, int y, Pantalla pantalla);





		/// Obtiene la información del nivel.
		bool obtener(int identificador);

		/// Actualiza la información del nivel.
		bool actualizar();

	private:
		
		/// Identificador del nivel.
		int identificador;

		/// Nombre del nivel.
		string nombre;

		/// Nivel de dificultad.
		int dificultad;

		/// Pantalla inicial.
		Coordenada2D pantallaInicial;

		/// Pantalla final.
		Coordenada2D pantallaFinal;

		/// Pantalla actual.
		Coordenada2D pantallaActual;

		/// Matriz de pantallas.
		Pantalla** pantallas;

	protected:
};

#endif

