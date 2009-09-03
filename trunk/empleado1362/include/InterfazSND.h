/// Fichero de cabecera de la clase InterfazSND.
/** \file InterfazSND.h
 */
	
#ifndef _INTERFAZSND_H
#define _INTERFAZSND_H

#include <string>
#include <math.h>
#include <irrKlang.h>
#include <iostream>

using namespace std;
using namespace irrklang;

/// Esta clase está diseñada con el patrón 'singleton' y se encarga de administrar los sonidos.
/** Soporta los formatos WAV y OGG y permite reproducir sonidos globales (2D) y puntuales (3D).
 * Hace uso de la librería irrKlang.
 */
class InterfazSND
{
	public:
		
		/// Obtiene la única instancia del gestor de sonidos.
		/** Si es la primera vez que se obtiene la instancia, se llama al
		 * constructor. Si no, sólo devuelve la referencia a la instancia.
		 * Se delega al usuario la responsabilidad de liberar la instancia
		 * cuando finalice la aplicación:     delete GestorSonido::getInstancia();
		 * \return Devuelve un puntero a la única instancia del gestor de sonidos.
		 */
		static InterfazSND* getInstancia();

		/// Destructor por defecto.
		~InterfazSND();

		/// Inicia la interfaz.
		void iniciar();

		/// Reproduce el sonido.
		/** Una vez que se llama al método, el proceso que lo invocó debe seguir vivo el tiempo suficiente
		 * para completar la reproducción.
		 * \param ficheroSonido Nombre (ruta) del fichero de sonido que se va a reproducir.
		 * \param bucle Indica si se reproducirá en un bucle o sólo una vez.
		 */
		void reproducir (string ficheroSonido, bool bucle=false);
	    
	private:
	
		/// Reproduce el sonido.
		/** Una vez que se llama al método, el proceso que lo invocó debe seguir vivo el tiempo suficiente
		 * para completar la reproducción.
		 * En esta sobrecarga del método se puede indicar una posición en el espacio (x, y, z) donde se
		 * reproducirá el sonido. Según la posición del observador y la posición de reproducción, se escuchará
		 * a más o menos volumen.
		 * \param ficheroSonido Nombre (ruta) del fichero de sonido que se va a reproducir.
		 * \param x Componente x de la coordenada de posición del sonido.
		 * \param y Componente y de la coordenada de posición del sonido.
		 * \param z Componente z de la coordenada de posición del sonido.
		 * \param bucle Indica si se reproducirá en un bucle o sólo una vez.
		 */
		void reproducir (string ficheroSonido, float x, float y, float z, bool bucle=false);

		/// Comprueba si el sonido está reproduciéndose actualmente.
		/** \param ficheroSonido Nombre (ruta) del fichero de sonido sobre el que se va a operar.
		 * \return Devuelve verdadero si está reproduciéndose. Falso en caso contrario.
		 */
		bool reproduciendose (string ficheroSonido) const;

		/// Detiene el sonido.
		/** \param ficheroSonido Nombre (ruta) del fichero de sonido sobre el que se va a operar.
		 * \return Devuelve verdadero si el sonido estaba reproduciéndose y lo ha detenido. Falso si ya estaba detenido.
		 */
		bool detener (string ficheroSonido);

		/// Comprueba si el sonido está cargado.
		/** Un sonido está cargado correctamente si ya se ha reproducido en alguna ocasión y no se ha detenido.
		 * \param ficheroSonido Nombre (ruta) del fichero de sonido sobre el que se va a operar.
		 * \return Devuelve verdadero si está cargado.
		 */
		bool cargado (string ficheroSonido) const;

		/// Modifica el estado del sonido.
		/** Se activan o desactivan los sonidos. Si están desactivados, aunque se intente reproducir, no se escuchará nada.
		 * Si cuando se desactivó había sonidos reproduciéndose, continuarán por donde iban.
		 * \param activado Nuevo valor para el estado del sonido.
		 */
		void setActivado (bool activado);

		/// Comprueba si el sonido está activado.
		/** \return Devuelve verdadero si el sonido está activado. Falso en caso contrario.
		 */
		bool getActivado () const;

		/// Modifica el volumen del dispositivo de sonido.
		/* \param volumen Nuevo valor para el volumen del sonido (entre 0 y 1).
		 */
		void setVolumen (float volumen);

		/// Obtiene el volumen actual del dispositivo de sonido.
		/** \return Devuelve el valor del sonido (entre 0 y 1).
		 */
		float getVolumen () const;

		/// Establece la posición del oyente.
		/** Según la posición del oyente y la posición de reproducción de los sonidos, se escucharán a mayor o
		 * menor volumen. Si un sonido se reproduce sin utilizar el método que permite indicar una posición, no se verá
		 * afectado por la posición del oyente.
		 * \param x Componente x de la coordenada de posición del oyente.
		 * \param y Componente y de la coordenada de posición del oyente.
		 * \param z Componente z de la coordenada de posición del oyente.
		 */
		void setPosicionOyente (float x, float y, float z);

		/// Obtiene la posición del oyente.
		/** \return Devuelve un vector de tamaño 3 que contiene los valores x,y,z de la posición del oyente. No se debe liberar este puntero.
		 */
		float* getPosicionOyente ();

		/// Establece la mínima distancia para comenzar la atenuación de sonido.
		/** Si la distancia es menor que la mínima distancia, el volumen del sonido será 1. Si la distancia
		 * está entre la máxima y la mínima, el volumen del sonido estará entre 0 y 1 (se reduce progresivamente al
		 * alejarse de la posición del oyente).
		 * \param minimaDistancia Nuevo valor para la mínima distancia.
		 */
		void setMinimaDistancia (float minimaDistancia);

		/// Establece la máxima distancia a la que un sonido puede reproducirse.
		/** Si la distancia es mayor que la máxima distancia, el volumen del sonido será 0. Si la distancia
		 * está entre la máxima y la mínima, el volumen del sonido estará entre 0 y 1 (se reduce progresivamente al
		 * alejarse de la posición del oyente).
		 * \param maximaDistancia Nuevo valor para la máxima distancia.
		 */
		void setMaximaDistancia (float maximaDistancia);


	private:

		/// Indica la posición del oyente en (x,y,z).
		float posicionOyente[3];

		/// Distancia a la que los sonidos comienzan a reducir su volumen.
		/** Los sonidos que se reproducen indicando una posición de emisión, reducirán su volumen según se
		 * alejen del oyente. Hasta que no se sobrepasa esta distancia, no comienza a disminuir el volumen.
		 */
		float minimaDistancia;

		/// Distancia a la que los sonidos alcanzan un volumen nulo.
		/** Cuando un sonido está más lejano al oyente que la distancia mínima, comienza a disminuir su volumen.
		 * Una vez sobrepase la distancia máxima, su volumen será 0.
		 */
		float maximaDistancia;

		/// Constructor por defecto.
		/** Se encuentra en el ámbito privado para impedir más de una instancia
		 * del gestor de sonidos.
		 */
		InterfazSND();

		/// Puntero a la única instancia del gestor de sonidos.
		/** Se inicializa a NULL en la definición de la clase y sólo se crea
		 * el objeto en la primera llamada a getInstancia().
		 */
		static InterfazSND* instancia;

		/// Referencia al dispositivo de sonido de irrKlang.
		ISoundEngine* engine;

		/// Indica si el sonido está activado.
		bool activado;
	
	protected:
	
};
		
#endif

