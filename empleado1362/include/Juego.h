/// Fichero de cabecera de la clase Juego.
/** \file Juego.h
 */

#ifndef _JUEGO_H
#define _JUEGO_H

#include "InterfazGFX.h"
#include "InterfazIA.h"
#include "InterfazPSX.h"
#include "InterfazINF.h"
#include "InterfazSND.h"
#include "Nivel.h"
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>
#include <iostream>

using namespace std;

/** Clase base del juego
*/
class Juego
{
	public:

		/// Constructor por defecto
		Juego();

		/// Destructor por defecto
		~Juego();





		/// Inicia el juego
		void iniciar();

		/// Actualiza el juego.
		void actualizar();

		/// Realiza un render.
		void render();

		/// Procesa los eventos de teclado.
		//bool procesarTeclado(const FrameEvent& evt);
		bool procesarTeclado();

		/// Procesa los eventos del ratón.
		//bool procesarRaton(const FrameEvent& evt);
		bool procesarRaton();


		
		
		
		/// Obtiene el mInput Manager.
		OIS::InputManager* getmInputManager() const;
		
		/// Establece el mInput Manager.
		void setmInputManager(OIS::InputManager* mInputManager);

		/// Obtiene el mMouse.
		OIS::Mouse* getmMouse() const;

		/// Establece el mMouse.
		void setmMouse(OIS::Mouse* mMouse);

		/// Obtiene el mKeyboard.
		OIS::Keyboard* getmKeyboard() const;

		/// Establece el mKeyboard.
		void setmKeyboard(OIS::Keyboard* mKeyboard);

		/// Establece todos los input devices.
		void setInputDevices(OIS::InputManager* mInputManager, OIS::Mouse* mMouse, OIS::Keyboard* mKeyboard);

	private:
		
		/// Barrera de abstracción para los gráficos del juego.
		InterfazGFX* interfazGFX;
		
		/// Barrera de abstracción para la IA del juego.
		InterfazIA* interfazIA;
		
		/// Barrera de abstracción para la física del juego.
		InterfazPSX* interfazPSX;
		
		/// Barrera de abstracción para la información del juego.
		InterfazINF* interfazINF;
		
		/// Barrera de abstracción para el sonido del juego.
		InterfazSND* interfazSND;

		/// Niveles del juego
		Nivel* niveles;

		//OIS Input devices
		OIS::InputManager* mInputManager;
		OIS::Mouse* mMouse;
		OIS::Keyboard* mKeyboard;
		
		/// ADSF
		int done;

	protected:
	
};
		
#endif
