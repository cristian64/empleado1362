/// Fichero de cabecera de la clase Nivel.
/** \file Nivel.h
 */

#ifndef _NIVEL_H
#define	_NIVEL_H


#include "Pantalla.h"
#include "Coordenada.h"
#include "InterfazINF.h"
#include "Matriz.h"
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
		int getIdentificador() const;

		/// Establece el identificador del nivel.
		void setIdentificador(int identificador);

		/// Obtiene el nombre del nivel.
		string getNombre() const;

		/// Establece el nombre del nivel.
		void setNombre(string nombre);

		/// Obtiene la dificultad del nivel.
		int getDificultad() const;

		/// Establece la dificultad del nivel.
		void setDificultad(int dificultad);

		/// Obtiene la coordenada de la pantalla inicial.
		Coordenada getPantallaInicial() const;

		/// Establece la coordenada de la pantalla inicial.
		void setPantallaInicial(Coordenada pantallaInicial);

		/// Obtiene la coordenada de la pantalla final.
		Coordenada getPantallaFinal() const;

		/// Establece la coordenada de la pantalla final.
		void setPantallaFinal(Coordenada pantallaFinal);

		/// Obtiene la coordenada de la pantalla actual.
		Coordenada getPantallaActual() const;

		/// Establece la coordenada de la pantalla actual.
		void setPantallaActual(Coordenada pantallaActual);

		/// Obtiene las pantallas.
		Matriz<Pantalla> getPantallas() const;

		/// Establece las pantallas.
		void setPantallas(Matriz<Pantalla> pantallas);
		
		/// Obtiene la Pantalla a través de una Coordenada.
		Pantalla getPantalla(Coordenada coordenada) const;

		/// Obtiene la Pantalla indicando la coordenada.
		Pantalla getPantalla(int x, int y) const;

		/// Establece la pantalla a través de una Coordenada.
		void setPantalla(Coordenada coordenada, Pantalla pantalla);

		/// Establece la pantalla indicando la coordenada.
		void setPantalla(int x, int y, Pantalla pantalla);





		/// Obtiene la información del nivel.
		bool obtener(int identificador);

		/// Actualiza la información del nivel.
		bool actualizar() const;

	private:
		
		/// Identificador del nivel.
		int identificador;

		/// Nombre del nivel.
		string nombre;

		/// Nivel de dificultad.
		int dificultad;

		/// Pantalla inicial.
		Coordenada pantallaInicial;

		/// Pantalla final.
		Coordenada pantallaFinal;

		/// Pantalla actual.
		Coordenada pantallaActual;

		/// Matriz de pantallas.
		Matriz<Pantalla> pantallas;

	protected:
};

#endif

