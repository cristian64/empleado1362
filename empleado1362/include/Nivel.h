/// Fichero de cabecera de la clase Nivel.
/** \file Nivel.h
 */

#ifndef _NIVEL_H
#define	_NIVEL_H


#include "Pantalla.h"
#include "InterfazINF.h"
#include <list>
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

		/// Obtiene la pantalla inicial.
		Pantalla* getPantallaInicial() const;

		/// Establece la pantalla inicial.
		void setPantallaInicial(Pantalla* pantallaInicial);

		/// Obtiene la pantalla final.
		Pantalla* getPantallaFinal() const;

		/// Establece la pantalla final.
		void setPantallaFinal(Pantalla* pantallaFinal);

		/// Obtiene la pantalla actual.
		Pantalla* getPantallaActual() const;

		/// Establece la pantalla actual.
		void setPantallaActual(Pantalla* pantallaActual);

		/// Obtiene las pantallas.
		list<Pantalla*> getPantallas() const;

		/// Establece las pantallas.
		void setPantallas(list<Pantalla*> pantallas);
		
		/// Obtiene la Pantalla a través de un id.
		Pantalla* getPantalla(int idPantalla) const;

		/// Establece la pantalla a través de un id.
		void setPantalla(int idPantalla, Pantalla* pantalla);



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
		Pantalla* pantallaInicial;

		/// Pantalla final.
		Pantalla* pantallaFinal;

		/// Pantalla actual.
		Pantalla* pantallaActual;

		/// Matriz de pantallas.
		list<Pantalla*> pantallas;

	protected:
};

#endif

