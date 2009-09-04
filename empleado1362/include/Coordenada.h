/// Fichero de cabecera de la clase Coordenada.
/** \file Coordenada.h
 */

#ifndef _COORDENADA_H
#define	_COORDENADA_H

#include <math.h>
#include <iostream>

using namespace std;


/// La clase coordenada representa una posición en el espacio R³.
/** TIene las componente (x,y,z).
 */
class Coordenada
{
	/// Operador de salida.
	/** Muestra en el flujo de salda la coordenada con formato Coordenada [x , y , z].
	 * \param os Flujo de salida donde se va a mostrar la coordenada.
	 * \param coordenada Coordenada que se va a mostrar por pantalla.
	 * \return Devuelve el flujo de salida recibido para concatenar salidas.
	 */
	friend ostream& operator<<(ostream& os, const Coordenada &coordenada);
	
	public:
		
		/// Constructor por defecto.
		/** Crea una coordenada e inicializa sus valores. Por defecto, todos 0.
		 * \param x Valor de la componente x.
		 * \param y Valor de la componente y.
		 * \param z Valor de la componente z.
		 */
		Coordenada(float x = 0, float y = 0, float z = 0);
		
		/// Constructor de copia.
		/** Crea un objeto a partir de otro.
		 * \param origen Coordenada original que va a ser copiada.
		 */
		Coordenada(const Coordenada &origen);
		
		/// Destructor.
		~Coordenada();
		
		/// Operador de asignación.
		/** Asigna una coordenada a la coordenada que invocó el método.
		 * \param origen Coordenada original que va a ser asignada.
		 * \return Devuelve la referencia al objeto que invocó el método para concatenar asignaciones.
		 */
		Coordenada& operator= (const Coordenada &origen);
		
		/// Operador de igualdad
		/** Compara si las coordendas son iguales
		 * \param origen  Coordenada original que vamos a usar para comparar.
		 * \return Devuelve true si son iguales y false en caso contrario
		 */
		bool operator== (const Coordenada &origen) const;

		/// Operador de desigualdad
		/** Compara si las coordendas son distintas
		 * \param origen  Coordenada original que vamos a usar para comparar.
		 * \return Devuelve true si son distintas y false en caso contrario
		 */
		bool operator!= (const Coordenada &origen) const;
		
		/// Operador suma.
		/** Suma la coordenada recibida y la que invocó el método componente a componente.
		 * \param origen Coordenada original que va a sumar.
		 * \return Devuelve la coordenada resultado.
		 */
		Coordenada operator+ (const Coordenada &origen) const;
		
		/// Operador resta.
		/** Resta la coordenada recibida y la que invocó el método componente a componente, (invocador-origen).
		 * \param origen Coordenada original que va a resta.
		 * \return Devuelve la coordenada resultado.
		 */
		Coordenada operator- (const Coordenada &origen) const;
		
		/// Multiplica una coordenada por un escalar.
		/** \param escalar Valor decimal por el que se van a multiplicar las componentes de la coordenada.
		 * \return Devuelve la coordenada resultado.
		 */
		Coordenada operator* (float escalar) const;
		
		/// Asigna el valor para la componente x.
		/** \param x Nuevo valor para la componente x.
		 */
		void setX(float x);
		
		/// Asigna el valor para la componente y.
		/** \param y Nuevo valor para la componente y.
		 */		
		void setY(float y);
		
		/// Asigna el valor para la componente z.
		/** \param z Nuevo valor para la componente z.
		 */
		void setZ(float z);
		
		/// Obtiene el valor de la componente x.
		/** \return Devuelve el valor decimal de la componente x.
		 */
		float getX() const;
		
		/// Obtiene el valor de la componente y.
		/** \return Devuelve el valor decimal de la componente y.
		 */
		float getY() const;
		
		/// Obtiene el valor de la componente z.
		/** \return Devuelve el valor decimal de la componente z.
		 */
		float getZ() const;
		
		/// Obtiene el vector con las 3 componentes.
		/** \return Devuelve una referencia al vector con las 3 componentes de la coordenada. No se debe liberar este puntero.
		 */
		float* getCoordenada();
		
		/// Inicializa la coordenada.
		/** \param x Valor para la componente x.
		 * \param y Valor para la componente y.
		 * \param z Valor para la componente z.
		 */
		void inicializar(float x, float y, float z);
		
		/// Calcula la distancia absoluta entre 2 coordenadas.
		/* \param coordenada Coordenada con la que se va a calcular la distancia.
		 * \return Devuelve un valor decimal con la distancia entre la coordenada que invocó el método y la recibida en los parámetros.
		 */
		float distancia (const Coordenada &coordenada) const;
		
		/// Calcula el módulo de una coordenada.
		/** \return Devuelve un valor decimal con el módulo.
		 */
		float modulo () const;
		
		/// Calcula el ángulo que forma el vector de dirección formado por dos coordenadas.
		/** \param coordenada Coordenada con la que forma un vector de dirección.
		 * \return Devuelve un valor decimal que es el ángulo, en grados, que forma el vector con el eje OX.
		 */
		float angulo (const Coordenada &coordenada) const;
		
		/// Normaliza la coordenada.
		/** Divide cada componente entre el módulo del vector que representa la coordenada.
		 */
		void normalizar();
		
		
	private:
		
		/// Vector con las componentes de la coordenada.
		float coordenada[3];
		
};

#endif

