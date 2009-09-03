/// Fichero de cabecera de la clase ManejadorEventos.
/** \file ManejadorEventos.h
 */

#ifndef _MANEJADOREVENTOS_H
#define _MANEJADOREVENTOS_H

#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>
#include <iostream>

using namespace std;

/** Clase que se encarga de manejar los eventos de teclado y ratón.
*/
class ManejadorEventos
{
	public:
		
		/// Constructor por defecto.
		ManejadorEventos();
		
		/// Destructor.
		~ManejadorEventos();
		
		/// Procesa los eventos de teclado.
		//bool procesarTeclado(const FrameEvent& evt);
		bool procesarTeclado();
		
		/// Procesa los eventos del ratón.
		//bool procesarRaton(const FrameEvent& evt);
		bool procesarRaton();
		
	private:
	
		//OIS Input devices
		OIS::InputManager* mInputManager;
		OIS::Mouse* mMouse;
		OIS::Keyboard* mKeyboard;
	
	protected:

};

#endif
